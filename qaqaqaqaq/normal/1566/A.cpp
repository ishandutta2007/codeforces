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

int n,m;
void solve(){
    cin>>n>>m;
    int non=n/2+1;
    cout<<m/non<<"\n";
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