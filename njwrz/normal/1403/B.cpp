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
int a[100005],n; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	if(n==1){
		cout<<"1 1\n"<<-a[1]<<'\n';
		cout<<"1 1\n0\n1 1\n0";RE 0;
	}
	cout<<1<<' '<<1<<'\n';
	cout<<-a[1]<<'\n';a[1]=0;
	cout<<2<<' '<<n<<'\n';
	FOR(i,2,n){
		cout<<(a[i]%n)*(n-1)<<' ';
		a[i]+=(a[i]%n)*(n-1);
	}
	cout<<'\n';
	cout<<1<<' '<<n<<'\n';
	FOR(i,1,n){
		cout<<-a[i]<<' ';
	}
	RE 0;
}