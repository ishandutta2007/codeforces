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
int a[100005],lsta[100005],lstb[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	set<P<int,int> >sa,sb;
	sa.emplace(MP(0,0));
	sb.emplace(MP(0,0));
	FOR(i,1,n){
		int k,al,ar,bl,br;
		cin>>k>>al>>ar>>bl>>br;a[i]=k;
		bool fa=!sa.empty(),fb=!sb.empty();
		if(fb)lsta[i]=(*sb.begin()).S;
		if(fa)lstb[i]=(*sa.begin()).S;
		while(!sb.empty()&&(*sb.begin()).F<al)sb.erase(sb.begin());
		while(!sb.empty()){
			auto iter=sb.end();iter--;
			if((*iter).F>ar)sb.erase(iter);else break;
		}
		while(!sa.empty()&&(*sa.begin()).F<bl)sa.erase(sa.begin());
		while(!sa.empty()){
			auto iter=sa.end();iter--;
			if((*iter).F>br)sa.erase(iter);else break;
		}
		if(fa&&a[i-1]>=al&&a[i-1]<=ar)sb.emplace(MP(a[i-1],i-1));
		if(fb&&a[i-1]>=bl&&a[i-1]<=br)sa.emplace(MP(a[i-1],i-1));
		if(k<al||k>ar)sa.clear();
		if(k<bl||k>br)sb.clear();
	}
	if(sa.empty()&&sb.empty()){
		cout<<"No";
	}else {
		cout<<"Yes\n";
		int now=1,t=n;
		V<int> v;
		if(!sa.empty()){
			now=0;
			t=(*sa.begin()).S+1;
			FOR(i,t,n)v.PB(0);
		}else {
			now=1;
			t=(*sb.begin()).S+1;
			FOR(i,t,n)v.PB(1);
		}
		while(t>1){
			if(now){
				rep(i,lstb[t]+1,t)v.PB(0);
				t=lstb[t]+1;
			}else{
				rep(i,lsta[t]+1,t)v.PB(1);
				t=lsta[t]+1;
			}
			now^=1;
		}
		reverse(ALL(v));
		for(auto u:v)cout<<u<<' ';
	}
	RE 0;
}