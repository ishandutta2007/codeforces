#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,d;
const ll big = 1000000007;
ll s;
vector<vl> C(1501, vl());
vl A;
vl A2;
set<ll> S;
bool mark[1501] ={0};
vector<pair<ll,ll> > segs;

vi inds;

ll GO[1501] = {0};

ll CS[1502] = {0};
ll DP[1501][1501] = {0};
ll DPC[1501][1501] = {0};
ll glob = 0;

ll dp(ll i, ll kvar){
    if(kvar <= 0)return 0;
    if(i >= n)return 0;
    if(DPC[i][kvar] == glob)return DP[i][kvar];
    ll extra = 0;
    if(GO[i] != i){
        extra = CS[GO[i]]-CS[i]+dp(GO[i],kvar-1);
    }

    ll ans = max(dp(i+1,kvar),extra);
    DPC[i][kvar] = glob;
    DP[i][kvar] = ans;
    return ans;
}


bool test(ll i){
    glob++;

    CS[0] = 0;
    for(int c1 = 0; c1 < n; c1++){
        CS[c1+1] = CS[c1]+(A[c1] <= i);
    }

    ll f = 0;
    for(int c1 = 0; c1 < sz(inds); c1++){
        if(dp(c1,m) >= k)return 1;
    }
    return 0;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> s >> m >> k;

    for(int c1 = 0; c1 < n; c1++){
        GO[c1] = c1;
    }

    for(int c1 = 0; c1<n; c1++){
        cin >> a;
        A.push_back(a);
        if(S.find(a) == S.end())A2.push_back(a);
        S.insert(a);
    }
    ll sumc = 0;
    for(int c1 = 0; c1 < s; c1++){
        cin >> a >> b;
        a--;
        b--;
        segs.push_back({a,b});
        for(int c2 = a; c2 <= b; c2++){
            GO[c2] = max(GO[c2],b+1);
            C[c1].push_back(c2);
            if(!mark[c2]){
                inds.push_back(c2);
            }
            mark[c2] = 1;
        }
        sort(all(C[c1]));
        sumc += sz(C[c1]);
    }

    sort(all(A2));
    ll tot = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(mark[c1])tot++;
    }

    ll l = 0;
    ll r = sz(A2)-1;

    if(!test(A2[sz(A2)-1])){
        cout << "-1\n";
        return 0;
    }

    if(test(A2[l])){
        cout << A2[l] << "\n";
        return 0;
    }


    while(l < r-1){
        ll mid = (l+r)/2;
        if(test(A2[mid])){
            r = mid;
        }
        else{
            l = mid;
        }

    }

    cout << A2[r] << "\n";

    return 0;
}