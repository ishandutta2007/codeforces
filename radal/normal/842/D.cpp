#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e7,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int trie[N][3],cnt,a[N];
int num[N];
void build(int v){
    int p = 0;
    repr(i,18,0){
        bool d = (v&(1 << i));
        if (!trie[p][d]){
            cnt++;
            trie[p][d] = cnt;
            num[cnt] = (1 << i);
        }
        p = trie[p][d];
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    set<int> st;
    num[0] = N;
    rep(i,0,n){
        cin >> a[i];
        st.insert(a[i]);
    }
    n = st.size();
    int in=0,k = (1 << 19);
    build(2);
    rep(i,0,k) build(i);
    for(int u : st){
        a[in] = u;
        in++;
        int p = 0;
        repr(i,18,0){
            bool d = (u&(1 << i));
            num[p]--;
            p = trie[p][d];
        }
        num[p]--;
    }
    int x = 0;
    rep(j,0,m){
        int y;
        cin >> y;
        x ^= y;
        int p = 0,ans = 0;
        repr(i,18,0){
            bool f = (x&(1<<i));
            ans*=2;
            if (!f){
                if (num[trie[p][0]])
                    p = trie[p][0];
                else{
                    p = trie[p][1];
                    ans++;
                }
            }
            else{
                if (num[trie[p][1]])
                    p = trie[p][1];
                else{
                    p = trie[p][0];
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}