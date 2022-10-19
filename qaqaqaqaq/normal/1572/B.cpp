// #pragma comment(linker, "/STACK:102400000,102400000")
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

const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!

const int maxn=600007;
const int mod=998244353;
const double EPS=1e-9;
const int ofs=500*57;
const double pi=3.14159265358979;


int n;
int a[maxn];

void generate(){
    n=15;
    rep(i,n) a[i]=rng()%2;
}
void solve(){
    cin>>n;
    // generate();
    // rep(i,n) cerr<<a[i]<<" ";
    // cerr<<endl;
    int cnt=0;
    rep(i,n) cin>>a[i], cnt+=a[i];
    if ((cnt&1)||(cnt==n)){
        cout<<"NO\n";
        return;
    }
    vi res;
    res.clear();
    auto change=[&](int u){
        if (u+2>=n) return;
        assert(u>=0);
        // cerr<<u<<endl;
        res.pb(u);
        int res=a[u]^a[u+1]^a[u+2];
        a[u]=a[u+1]=a[u+2]=res;
    };
    int lst=0;
    while (1){
        bool ok=0;
        for (int i=lst;i<n;++i){
            if (!a[i]){lst=i; ok=1; break;}
        }
        if (!ok){
            cout<<"NO\n";
            return;
        }
        if (lst%2==0){
            for (int i=lst;i>1;i-=2) change(i-2);
            break;
        }
        int nxt=lst;
        for (int i=lst;i<n;++i){
            if (a[i]) {nxt=i; break;}
        }
        if (nxt%2==0){
            for (int i=nxt;i>1;i-=2) change(i-2);
            break;
        }
        else{
            for (int i=nxt;i>lst;i-=2) change(i-2);
            lst=nxt;
        }
    }
    assert(!a[0]);
    rep(i,n-1){
        if (a[i]){
            if (a[i+1]) change(i-1);
            else {
                change(i);
                if (a[i]) change(i-1);
            }
        }
    }
    cout<<"YES\n";
    rep(i,n) assert(!a[i]);
    // assert(sz(res)<=n);
    cout<<sz(res)<<"\n";
    for (auto c:res) cout<<c+1<<" ";
    cout<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(20);
    int _;
    cin>>_;
    while (_--) solve();
    return 0;
}

/*
2
101919804931827191 136638622643121931

*/