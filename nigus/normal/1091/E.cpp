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

ll n,m,T,k;
const ll big = 1000000007;
const ll big2 = 998244353;

ll CS[1000005] = {0};
vl D;
ll parity = 0;

ll A[500003] = {0};
ll B[500003] = {0};
ll pref[500003] = {0};

ll F[500003] = {0};
ll F2[500003] = {0};

void bad(ll i, ll j){
    if(i > j)return;
    CS[i]++;
    CS[j+1]--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,e;

    cin >> n;
    ll sum01 = 0;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        D.push_back(a);
        parity += a;
        parity %= 2;
        sum01 += min(1,a);
        F[a]++;
    }
    sort(all(D));
    reverse(all(D));

    bad(sum01+1,n);
    pref[0] = 0;
    for(ll c1 = 0; c1 < n; c1++){
        pref[c1+1]=pref[c1]+D[c1];
    }

    ll bads1 = 0;
    ll bads2 = 0;

    for(ll c1 = n-1; c1 >= 0; c1--){

        F2[D[c1]]++;

        if(D[c1] > c1)bads1++;
        if(D[c1] > c1+1)bads2++;

        bads1 += F2[c1];
        bads2 += F2[c1+1];

        A[c1] = pref[n]-pref[c1+bads1] + bads1*c1;

        B[c1] = pref[n]-pref[c1+bads2] + bads2*(c1+1);
    }

    for(ll c1 = 1; c1 < n; c1++){
        k = c1;
        ll dk = D[c1];
        bad(max(k*(k+1)+B[k]-pref[k]  + 1 , D[c1]),n);
        ll r = pref[k]-k*(k-1)-A[k];

        bad(0,min(dk,r-1));
        if(k <= dk && k < r){
            bad(k,dk);
        }

    }


    ll cs = 0;
    bool yes = 0;
    for(ll c1 = 0; c1 <= n; c1++){
        cs += CS[c1];
        if(cs == 0 && c1%2 == parity){
            cout << c1 << " ";
            yes = 1;
        }
    }

    if(!yes){
        cout << "-1\n";
    }

    return 0;
}