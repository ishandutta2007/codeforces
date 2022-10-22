#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n;
P<int,int> p[505];
deque<int> v;
V<P<int,int> > ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int sum=0;
	FOR(i,1,n){
		cin>>p[i].F;sum+=p[i].F;
		p[i].S=i;
	}
	if(sum<(n-1)*2){
		cout<<"NO";RE 0;
	}
	sort(p+1,p+n+1);
	int l=1;
	while(p[l].F==1)l++;
	int t=min(2,l-1);
	int ant=n-l+t;
	cout<<"YES "<<ant<<'\n';
	FOR(i,l,n)v.PB(i);
	if(l>1)v.push_front(1);
	if(l>2)v.PB(2);
	rep(i,0,v.size()-1){
		p[v[i]].F--;p[v[i+1]].F--;
		ans.PB(MP(p[v[i]].S,p[v[i+1]].S));
	} 
	int last=0;
	rep(i,3,l){
		while(!p[v[last]].F)last++;
		p[v[last]].F--;
		ans.PB(MP(p[v[last]].S,p[i].S));
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
	RE 0;
}