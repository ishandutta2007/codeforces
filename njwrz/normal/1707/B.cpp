#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int a[100005];
int b[100005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int pos=1;
	for(int i=n;i>=2;i--){
		gmax(pos,2ll);
		for(int j=i-1;j>=pos-1;j--)b[j]=a[j+1]-a[j];
		rep(j,pos-1,i)a[j]=b[j];
//		cout<<pos<<' ';
		if(pos-1<=i)sort(a+pos-1,a+i);
		while(pos<i-1&&!a[pos])pos++;
		if(pos>1&&a[pos-1])pos--;
		gmin(pos,i-1);
//		FOR(j,1,n)cout<<a[j]<<' ';
//		cout<<'\n';
	}
	cout<<a[1]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}