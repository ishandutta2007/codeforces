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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int a[1005],n;
int val1,val[2];
char ans[1005];
int f[1005];
int ask(){
	FOR(i,1,n)if(f[i])cout<<'T';else cout<<'F';
	cout<<'\n';
	cout.flush();
	int re=0;
	cin>>re;
	if(re==n)exit(0);
	RE re;
}
signed main(){
	cin>>n;
	FOR(i,1,n)cout<<'T';
	cout<<'\n';
	cout.flush();
	cin>>val1;if(val1==n)RE 0;
	FOR(i,1,n)if(i&1)cout<<'F';else cout<<'T';
	cout<<'\n';
	cout.flush();
	cin>>val[1];if(val[1]==n)RE 0;
	FOR(i,1,n)if(i&1)cout<<'T';else cout<<'F';
	cout<<'\n';
	cout.flush();
	cin>>val[0];if(val[0]==n)RE 0;
	int pos=1;
	while(pos<=n){
		FOR(i,1,n)f[i]=1;
		if(pos==n){
			f[n]=0;
			int now=ask();
			if(now>val1)ans[n]='F';else ans[n]='T';
			break;
		}
		f[pos]=f[pos+1]=0;
		int now=ask();
		if(now==val1-2){
			ans[pos]=ans[pos+1]='T';pos+=2;continue;
		}
		if(now==val1+2){
			ans[pos]=ans[pos+1]='F';pos+=2;continue;
		}
		if(pos+1==n){
			FOR(i,1,n)f[i]=1;
			f[n]=0;
			int now=ask();
			if(now>val1){
				ans[n]='F';ans[n-1]='T';
			}else ans[n]='T',ans[n-1]='F';
			break;
		}
		int to;
		if(pos&1)to=val[1];else to=val[0];
		FOR(i,1,n)if((i&1)==(pos&1))f[i]=0;else f[i]=1;
		f[pos]=1;f[pos+1]=0;f[pos+2]=1;
		now=ask();
		if(now>to){
			ans[pos]='T';ans[pos+1]='F';
			if(now==to+3){
				ans[pos+2]='T';
			}else ans[pos+2]='F';
		}else{
			ans[pos]='F';ans[pos+1]='T';
			if(to==now+3){
				ans[pos+2]='F';
			}else ans[pos+2]='T';
		}
		pos+=3;
	}
	FOR(i,1,n)cout<<ans[i];
	cout<<'\n';
	cout.flush();
	RE 0;
}