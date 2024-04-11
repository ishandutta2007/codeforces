// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int maxn=300007;
const int mod=998244353;

int n,m;
int a[maxn],b[maxn],p[maxn];
int nxt[maxn],prv[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n;
    rep1(i,n){
        cout<<"? ";
        rep1(j,n){
            if (i==j) cout<<2<<" ";
            else cout<<1<<" ";
        }
        cout<<endl;
        cin>>a[i];
    }
    rep1(i,n){
        cout<<"? ";
        rep1(j,n){
            if (i==j) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
        cin>>b[i];
    }
    rep1(i,n){
        if (!a[i]) p[i]=n;
    }
    int beg=0;
    rep1(i,n){
        if (!b[i]) beg=i;
    }
    for (int i=1;i<=n;++i){
        if (a[i]==i||!a[i]) continue;
        nxt[i]=a[i];
    }
    for (int i=1;i<=n;++i){
        if (b[i]==i||!b[i]) continue;
        nxt[b[i]]=i;
    }
    p[beg]=1;
    for (int i=1;i<n;++i){
        p[nxt[beg]]=i+1;
        beg=nxt[beg];
        assert(beg>0);
    }
    cout<<"! ";
    rep1(i,n) cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}