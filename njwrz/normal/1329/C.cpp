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
int h,g;
int l[1050005]; 
ll ans;
V<int> v;
V<int> dfs(int p,int de){
	V<int> re={l[p]}; 
	if(de==h)RE re;
	V<int> a=dfs(p*2,de+1),b=dfs(p*2+1,de+1);
	reverse(ALL(a));reverse(ALL(b));
	if(de>=g){
		while(a.size()||b.size()){
			if(!b.size()||(a.size()&&a.back()>b.back())){
				re.PB(a.back());a.pop_back();
			}else{
				re.PB(b.back());b.pop_back();
			}
		}
	}else{
		while(a.size()>1||b.size()>1){
			if(!(b.size()>1)||(a.size()>1&&a.back()>b.back())){
				re.PB(a.back());a.pop_back();
			}else{
				re.PB(b.back());b.pop_back();
			}
			if(a.size()==1&&a.back()>b.back())break;
			if(b.size()==1&&b.back()>a.back())break;
		}
		ans+=a[0]+b[0];
		if(a.size()>1)rep(i,0,a.size()-1)v.PB(2*p);
		if(b.size()>1)rep(i,0,b.size()-1)v.PB(2*p+1);
	}
	RE re;
}
void solve(){
	cin>>h>>g;
	v.clear();ans=0;
	rep(i,1,1<<h)cin>>l[i];
	V<int> a=dfs(1,1);
	ans+=a.back();
	cout<<ans<<'\n';
	if(a.size()>1)rep(i,0,a.size()-1)cout<<"1 ";
	reverse(ALL(v));
	for(auto u:v)cout<<u<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}