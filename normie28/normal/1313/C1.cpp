#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)

#define FILE_IN "tree.inp"
#define FILE_OUT "tree.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define pow2(x) (ll(1)<<x)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define endl "\n"
#define finish(s) {cout<<s;return 0;}
ll n,m,i,j,k,t[200],cnt,p,nodes=1,fail=0;
ll dp[1<<15],e[20],a[500000],maxl[500000],maxr[500000],res[500000];
int main(){
	fio;
	cin>>n;
	vector<int> bruh;
	for (i=0;i<n;i++) cin>>a[i];
	cnt=0;
	for (i=0;i<n;i++)
	{
	    while ((bruh.size())and(a[i]<=a[bruh[bruh.size()-1]])) 
	    {
	        if (bruh.size()>=2) cnt-=(bruh[bruh.size()-1]-bruh[bruh.size()-2])*(a[bruh[bruh.size()-1]]);
	        else cnt-=(bruh[bruh.size()-1]+1)*(a[bruh[bruh.size()-1]]);
	        bruh.pop_back();
	    }
	   bruh.push_back(i);
	        if (bruh.size()>=2) cnt+=(bruh[bruh.size()-1]-bruh[bruh.size()-2])*(a[bruh[bruh.size()-1]]);
	        else cnt+=(bruh[bruh.size()-1]+1)*(a[bruh[bruh.size()-1]]);
	        maxl[i]=cnt;
//	    cout<<cnt<<' ';
	}
	cnt=0;
	bruh.clear();
	for (i=n-1;i>=0;i--)
	{
	    while ((bruh.size())and(a[i]<=a[bruh[bruh.size()-1]])) 
	    {
	        if (bruh.size()>=2) cnt-=(-bruh[bruh.size()-1]+bruh[bruh.size()-2])*(a[bruh[bruh.size()-1]]);
	        else cnt-=(n-bruh[bruh.size()-1])*(a[bruh[bruh.size()-1]]);
	        bruh.pop_back();
	    }
	   bruh.push_back(i);
	        if (bruh.size()>=2) cnt+=(-bruh[bruh.size()-1]+bruh[bruh.size()-2])*(a[bruh[bruh.size()-1]]);
	        else cnt+=(n-bruh[bruh.size()-1])*(a[bruh[bruh.size()-1]]);
	        maxr[i]=cnt;
	        
//	    cout<<cnt<<' ';
	}
	k=0;
	for (i=0;i<n;i++) {//cout<<maxl[i]+maxr[i]-a[i]<<' '; 
	if (maxl[i]+maxr[i]-a[i]>maxl[k]+maxr[k]-a[k]) k=i;}
	res[k]=a[k];
	for (i=k-1;i>=0;i--) res[i]=min(res[i+1],a[i]);
	for (i=k+1;i<n;i++) res[i]=min(res[i-1],a[i]);
	for (i=0;i<n;i++) cout<<res[i]<<' ';
}
//a+1>b+c