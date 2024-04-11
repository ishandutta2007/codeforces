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
int cnt[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int x;
	cin>>n;
	FOR(i,1,n)cin>>x,cnt[x]++;
	set<P<int,int> > q;
	FOR(i,1,n){
		if(cnt[i]){
			q.emplace(MP(cnt[i],i));
		}
	}
	int m;
	char c;
	cin>>m;
	FOR(i,1,m){
		cin>>c>>x;
		if(c=='-'){
			q.erase(MP(cnt[x],x));
			cnt[x]--;
			if(cnt[x])q.emplace(MP(cnt[x],x));
		}else{
			if(cnt[x])q.erase(MP(cnt[x],x));
			cnt[x]++;
			q.emplace(MP(cnt[x],x));
		}
		int f=-1;
		auto it=q.lwb(MP(4,0));
		if(it==q.end()){
			cout<<"NO\n";continue;
		}
		P<int,int> p1=(*it);
		if(p1.F>7){
			cout<<"YES\n";continue;
		}
		q.erase(p1);
		if(p1.F>5){ 
			f=0;
		}
		P<int,int> p2;
		it=q.lwb(MP(2,0));
		if(it==q.end()){
			q.emplace(p1);
			cout<<"NO\n";continue;
		}
		p2=(*it);
		if(p2.F>3){
			q.emplace(p1);
			cout<<"YES\n";continue;
		}
		q.erase(it);
		if(f<0){
			it=q.lwb(MP(2,0));
			q.emplace(p1);
			q.emplace(p2);
			if(it==q.end()){
				cout<<"NO\n";continue;
			}
		}
		cout<<"YES\n";
		q.emplace(p1);
		q.emplace(p2);
	}
	RE 0;
}