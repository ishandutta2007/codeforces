#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,a[100005];
unordered_map<int,int> to[100005];
int num[100005];
int solve(){
	int B=255,ans=0;
	FOR(i,0,B){
		int cnt=0;
		FOR(j,1,n)num[j]=a[j]-j*i;
		sort(num+1,num+n+1);
		cnt=1;int lst=num[1];
		FOR(j,2,n){
			if(num[j]!=num[j-1]){
				gmax(ans,cnt);
				cnt=1;lst=num[j];
			}else cnt++;
		}
		gmax(ans,cnt);
	}
	FOR(i,1,n)to[i].clear();
	FOR(i,1,n){
		FOR(j,i+1,min(n,i+400)){
			if(a[j]>a[i]&&(a[j]-a[i])%(j-i)==0&&(a[j]-a[i])/(j-i)>B){
				if(!to[i].count((a[j]-a[i])/(j-i)))to[i][(a[j]-a[i])/(j-i)]=j;
			}
		}
	}
	FOR(i,1,n){
		for(auto u:to[i])if(u.S!=-1){
			int cnt=2,now=u.S,tt;
			while(to[now].count(u.F)&&to[now][u.F]!=-1){
				tt=to[now][u.F];to[now][u.F]=-1;
				cnt++;now=tt;
			}
			gmax(ans,cnt);
		}
	}
	RE ans;
}
signed main(){
//	freopen("in.txt","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int out=solve();
	reverse(a+1,a+n+1);
	gmax(out,solve());
	cout<<n-out;
	RE 0;
}