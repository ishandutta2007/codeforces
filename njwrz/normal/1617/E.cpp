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
int n;
int get(int x){
	int t=log2(x);
	if((1<<t)<x)t++;
	RE (1<<t)-x;
}
unordered_map<int,int> to,pos;
unordered_map<int,V<P<P<int,int>,int > > > mp;
int a[200005];
P<P<int,int>,int> num[200005];
int len=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int ans=0,a1=0,a2=0;
	FOR(i,1,n)cin>>a[i],pos[a[i]]=i;
	sort(a+1,a+n+1,greater<int>());
	FOR(i,1,n){
		int x=a[i];
		int cnt=0;
		while(x){
			int t=get(x);
			cnt++;
			mp[t].PB(MP(MP(cnt,x),pos[a[i]]));
			to[x]=t;
			if(pos.count(t)){
				if(cnt>ans){
					ans=cnt;
					a1=pos[a[i]];a2=pos[t];
				}
			}
			x=t;
		}
	}
	for(auto u:mp){
		len=0;
		for(auto tu:u.S){
			num[++len]=tu;
		}
		sort(num+1,num+len+1);
		P<P<int,int>,int > now=num[len];
		while(len&&num[len].F.S==now.F.S)len--;
		if(len){
			P<P<int,int>,int> p2=num[len];
			if(now.F.F+p2.F.F>ans){
				ans=now.F.F+p2.F.F;
				a1=now.S;a2=p2.S;
			}
		}
	}
	cout<<a1<<' '<<a2<<' '<<ans;
	RE 0;
}