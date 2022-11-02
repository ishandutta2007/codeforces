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
int er[65];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int u,v;
	int t,l;
	cin>>u>>v;
	if(u>v){
		cout<<-1;RE 0;
	}
	if(u==v){
		if(u){
			cout<<"1\n"<<u;
		}else cout<<0;
		RE 0;
	}
	t=v-u;
	if(t&1){
		cout<<-1;RE 0;
	}
	t=t/2;
	if(t+u==(t^u)){
		cout<<2<<'\n';
		cout<<t+u<<' '<<t<<'\n';
	}else{
		cout<<3<<'\n';
		cout<<u<<' '<<t<<' '<<t<<'\n';
	}
	RE 0;
}