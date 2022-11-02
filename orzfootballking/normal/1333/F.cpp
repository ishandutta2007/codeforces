#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int s[500005],p[500005],ans[500005]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)s[i]=1;
	FOR(i,1,n)for(int j=i+i;j<=n;j+=i)s[j]=i;
	sort(s+1,s+n+1);
	int t=1;
	FOR(i,1,n){
		while(s[t]<=i&&t<=n)t++;
		p[i]=t-1;
		if(!ans[p[i]])ans[p[i]]=i;
	}
	for(int i=n;i>=1;i--)if(!ans[i])ans[i]=ans[i+1];
	FOR(i,2,n)cout<<ans[i]<<' ';
	RE 0;
}