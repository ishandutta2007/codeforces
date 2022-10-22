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
bool vis[505];
signed main(){
	int n,k;
	cin>>n>>k;
	int now=n,add=0;
	while(now%k!=0||add%n!=0&&(add/n)*2+3>now/k){
		now+=2;add++;
		if(now>n*k){
			cout<<-1;fflush(stdout);RE 0;
		}
	}
	int ta=add/n;
	add%=n;
	priority_queue<P<int,int> > q;
	FOR(i,1,add){
		q.emplace(MP(ta*2+3,i));
	}
	FOR(i,add+1,n){
		q.emplace(MP(ta*2+1,i));
	}
	int ans=0;
	while(q.top().F!=0){
		cout<<"? ";
		FILL(vis,0);
		V<P<int,int> > out;
		FOR(i,1,k){
			P<int,int> t=q.top();
			if(vis[t.S]){
				while(vis[q.top().S]){
					out.PB(q.top());
					q.pop();
				}
				t=q.top();
			}
			q.pop();
			t.F--;
			cout<<t.S<<' ';
			q.emplace(t);
			vis[t.S]=1;
		}
		for(auto u:out)q.emplace(u);
		cout<<'\n';
		fflush(stdout);
		int x;
		cin>>x;
		ans^=x;
	}
	cout<<"! "<<ans;
	fflush(stdout);
	RE 0;
}