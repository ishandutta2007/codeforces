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

int n,m,T,k,d;
const ll big = 1000000007;

int A[11][100001] = {0};
int A2[11][100001] = {0};
ll ans = 0;
vi B;

ll common(int i){
    if(i >= n)return 0;

    B.clear();
    for(int c1 = 0; c1 < m; c1++){
        B.push_back(A2[c1][i]);
    }
    ll res = 0;

    for(int c1 = 0; c1 < n; c1++){
        ll r = A[0][B[0]];
        bool yes = 1;
        if(B[0] >= n){
            yes = 0;
            break;
        }
        for(int c2 = 1; c2 < m; c2++){
            if(B[c2] >= n){
                yes = 0;
                break;
            }
            if(A[c2][B[c2]] != r){
                yes = 0;
                break;
            }
            B[c2]++;
        }
        if(!yes)break;
        res++;
        B[0]++;
    }
    return res;
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d,e;
    scanf("%d",&n);
    scanf("%d",&m);

    for(int c1 = 0; c1 < m; c1++){
        for(int c2 = 0; c2 < n; c2++){
            scanf("%d",&a);
            a--;
            A[c1][c2] = a;
            A2[c1][a] = c2;
        }
    }

    ll i = 0;
    while(i < n){
        ll r = A[0][i];
        ll l = common(r);
        ans += (l*(l+1))/2;
        i += l;
    }
    cout << ans << "\n";
    return 0;
}