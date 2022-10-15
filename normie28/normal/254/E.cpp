#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define int long long
using namespace std;
template<class T,class L>bool smax(T&x,L y){return x<y?(x=y,1):0;}template<class T,class L>bool smin(T&x,L y){return y<x?(x=y,1):0;}
typedef pair<int,int> pii;
 
const int maxn=4e2+17;
int n,dp[maxn][maxn],a[maxn],v,cer[maxn][maxn],par[maxn][maxn];
struct fri{int l,r,w,idx;}f[maxn];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ifstream cin("input.txt");ofstream cout("output.txt");
    cin>>n>>v;
    for(int i=0;i<n;i++)
	cin>>a[i];
    int m;cin>>m;
    for(int i=0;i<m;i++)
	cin>>f[i].l>>f[i].r>>f[i].w,f[i].l--,f[i].r--,f[i].idx=i+1;
    sort(f,f+m,[](fri &a,fri &b){return a.w<b.w;});
    for(int i=n-1;~i;i--)
	for(int w=0;w<maxn;w++){
	    if(w + a[i] - v < 0)continue;
	    par[i][w]=min(a[i],w + a[i] - v),smax(dp[i][w],dp[i+1][min(a[i],w + a[i] - v)]);
	    int cnt=0,sum=0;
	    for(int j=0;j<m;j++){
		if(f[j].l<=i && i<=f[j].r)
		    cnt++,sum+=f[j].w;
		if(w + a[i] - v - sum<0)break;
		if(smax(dp[i][w],cnt + dp[i+1][min(a[i],w + a[i] - v - sum)]))
		    cer[i][w]=cnt,par[i][w]=min(a[i],w + a[i] - v - sum);
	    }
	}
    cout<<dp[0][0]<<'\n';
    /*for(int i=0;i<n;i++,cout<<'\n')
	for(int j=0;j<10;j++)
	cerr<<dp[i][j]<<' ';*/
    int ww=0;
    for(int i=0;i<n;i++){
	vector<int>go;
	for(int j=0;go.size() != cer[i][ww];j++)
	    if(f[j].l<=i && i<=f[j].r)
		go.pb(f[j].idx);
	cout<<go.size()<<' ';
	for(auto x:go)
	    cout<<x<<' ';
	cout<<'\n';
	ww = par[i][ww];
    }
    return 0;
}