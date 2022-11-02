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
int a[6][6]={
-1,-1,0,0,1,1,
-1,0,1,-1,0,1,
0,1,0,1,0,-1,
0,-1,1,-1,1,0,
1,0,0,1,-1,0,
1,1,-1,0,0,0
};
int d[6],n=6;
int ans[7],ml=1e9;
void print(int t){
	bool p[7];
	rep(i,0,7){
		p[6-i]=t%10;
		t/=10;
	}
	rep(i,0,7){
		rep(_,0,ans[i])cout<<(p[i]?'b':'a');
	}
	cout<<'\n';
}
int l[6]={1,1,0,1,0,0};
void solve(int t){
	int x[6];
	rep(i,0,6){
		x[i]=d[i]-l[i]*t;
		if(x[i]<0)RE;
	}
	int y[6]={},sum=t;
	rep(i,0,6){
		rep(j,0,6)y[i]+=x[j]*a[i][j];
		if(y[i]<0||(y[i]&1))RE;
		sum+=y[i]/2;
	} 
	if(sum<ml){
		ml=sum;
		rep(i,0,6)ans[i]=y[i]/2;
		ans[6]=t; 
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int maxi=0;
	rep(i,0,6){
		cin>>d[i];gmax(maxi,d[i]);
	}
	swap(d[2],d[3]);
	FOR(i,0,maxi)solve(i);
	if(ml==1e9){
		cout<<-1;
	}else{
		cout<<ml<<'\n';
		print(0);
		print(1111);
		print(110011);
		print(1010101);
	}
	RE 0;
}