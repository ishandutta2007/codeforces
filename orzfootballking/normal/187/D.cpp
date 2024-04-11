#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
set<P<int,int> > s;
int nxt[200005];
void red(int l,int r,int now){
	P<int,int> p=MP(l,-1);
	while(!s.empty()){
		auto u=s.lower_bound(p);
		if(u!=s.end()&&(*u).F<=r){
			nxt[(*u).S]=now+1;
			s.erase(u); 
		}else break;
	}
} 
int start[100005],a[100005],su[100005];
int n,m,rd,gr,tr,tim[100005],ans[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>gr>>rd;
	tr=gr+rd;
	FOR(i,0,n){
		cin>>a[i];
		su[i+1]=su[i]+a[i];
	}
	cin>>m;
	FOR(i,1,m){
		cin>>tim[i];
		s.insert(MP((tr-tim[i]%tr)%tr,n+i));
	}
	int l,r,sum=0;
	FOR(i,0,n+m)nxt[i]=n+1;
	rep(i,0,n){
		sum+=a[i];
		l=(sum+1)%tr;
		r=(sum+rd)%tr;
		if(l<=r){
			red(l,r,i);
		}else{
			red(l,tr-1,i);
			red(0,r,i);
		}
		s.insert(MP(sum%tr,i+1));
	}
	int t;
	for(int i=n;i>=0;i--){
		if(nxt[i]==n+1){
			ans[i]=su[n+1]-su[i];
		}else{
			t=su[nxt[i]]-su[i];
			ans[i]=ans[nxt[i]]+t+tr-t%tr;
		}
	}
	FOR(i,1,m){
		t=su[nxt[n+i]]+tim[i];
		if(nxt[n+i]<=n){
			cout<<ans[nxt[n+i]]+t+tr-t%tr;
		}else{
			cout<<ans[nxt[n+i]]+t;
		}
		cout<<'\n';
	}
	RE 0;
}