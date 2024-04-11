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
int ch[30*100005][2],cnt[30*100005],m=27,num=1;
void solve1(){
	int t;
	cin>>t;
	int now=1;
	V<int> v;
	FOR(i,0,m){
		v.PB(now);
		int to=((1<<(m-i))&t)>0;
		if(!ch[now][to]){
			ch[now][to]=++num;
		}
		now=ch[now][to];
	}
	cnt[now]++;
	for(auto u:v)cnt[u]++;
}
void solve2(){
	int t;
	cin>>t;
	int now=1;
	V<int> v;
	FOR(i,0,m){
		v.PB(now);
		int to=((1<<(m-i))&t)>0;
		now=ch[now][to];
	}
	cnt[now]--;
	for(auto u:v)cnt[u]--;
}
void solve3(){
	int t,s;
	cin>>t>>s;
	int now=1,ans=0;
	FOR(i,0,m){
		int to=((1<<(m-i))&t)>0,so=((1<<(m-i))&s)>0;
		if(so){
			ans+=cnt[ch[now][to]];
//			cout<<ans<<' ';
		}
		now=ch[now][to^so];
		if(now==0)break;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _;
	cin>>_;
	while(_--){
		int t;
		cin>>t;
		if(t==1){
			solve1();
		}else if(t==2){
			solve2();
		}else{
			solve3();
		}
	}
	RE 0;
}