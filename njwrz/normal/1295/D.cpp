#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int gcd(int a,int b){
	if(!b)RE a;
	RE gcd(b,a%b);
}
void solve(){
	int a,m;
	cin>>a>>m;
	int t=gcd(a,m);
	a/=t;m/=t;
	int ans=m,la=m;
	for(int i=2;i*i<=la;i++){
		if(m%i==0){
			while(m%i==0)m/=i;
			ans=ans/i*(i-1);
		}
	}
	if(m!=1){
		ans=ans/m*(m-1);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}