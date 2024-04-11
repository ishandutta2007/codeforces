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
bool f[3005],t[3005];
int ans[10000005],cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	char c;
	FOR(i,1,n){
		cin>>c;
		t[i]=f[i]=(c=='R');
	}
	bool s;
	int l=0,r=0,tk=k;
	FOR(i,1,3*n){
		V<int> v;
		rep(j,1,n){
			if(f[j]&&!f[j+1])v.PB(j);
		}
		if(!v.size()){
			l=i-1;break;
		}
		for(auto u:v)swap(f[u],f[u+1]),ans[++cnt]=u;
		r+=v.size();
		ans[++cnt]=-1;tk--;
	}
	if(k>=l&&k<=r){
		V<int> v;
		FOR(i,1,cnt){
			if(ans[i]==-1){
				cout<<v.size()<<' ';
				for(auto u:v)cout<<u<<' ';
				cout<<'\n'; 
				v.clear();
				continue;
			}
			if(v.size()>0&&tk>0){
				tk--;
				cout<<v.size()<<' ';
				for(auto u:v)cout<<u<<' ';
				cout<<'\n'; 
				v.clear();
			}
			v.PB(ans[i]);
		}
	}else{
		cout<<-1;
	}
	RE 0;
}