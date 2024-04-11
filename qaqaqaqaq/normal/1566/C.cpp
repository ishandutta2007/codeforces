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

const int maxn=1000007;
const int mod=998244353;
const double EPS=1e-9;
const double pi=3.14159265358979;

int n;
string s,t;
void solve(){
    cin>>n;
    cin>>s>>t;
    int prv=0;
    int ans=0;
    rep(i,n){
        if (s[i]=='0'&&t[i]=='0'){
            if (prv==2) ans++;
            prv|=2;
            if (prv==3) ans+=2, prv=0;
        }
        if ((s[i]=='0'&&t[i]=='1')||(s[i]=='1'&&t[i]=='0')){
            if (prv==2) ans+=3;
            else ans+=2;
            prv=0;
        }
        if (s[i]=='1'&&t[i]=='1'){
            prv|=1;
            if (prv==3) ans+=2, prv=0;
        }
    }
    if (prv==2) ans++;
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(20);
    int _;
    cin>>_;
    while (_--){
        solve();
    }
    return 0;
}

/*
2
101919804931827191 136638622643121931

*/