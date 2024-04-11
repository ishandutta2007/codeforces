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
P<int,int> get(int s,int m){
	if(!s)RE MP(1,2);
	P<int,int> pa=get(s/4,m/4+(m%4!=0));
	pa.F=pa.F*4+(m-1)%4;
		pa.S=pa.S*4;
	if(m%4==1){
		
	}else if(m%4==2){
		pa.S+=2;
	}else if(m%4==3){
		pa.S+=3;
	}else{
		pa.S++;
	}
	RE pa;
}
int ans[4]={0,1,2,3};
void solve(){
	int s;
	cin>>s;
	if(s<=3){
		cout<<ans[s]<<'\n';RE ;
	}
	int q=s%3;
	if(!q)q=3;
	s=s/3+(s%3!=0);
	int t=1,sum=1;
	while(sum+t*4<s){
		sum=sum+t*4;
		t=t*4;
	}
	int m=s-sum;
	P<int,int> pa=get(t,m);
	if(q==1){
		cout<<pa.F<<'\n';
	}else if(q==2){
		cout<<pa.S<<'\n';
	}else cout<<(pa.F^pa.S)<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}