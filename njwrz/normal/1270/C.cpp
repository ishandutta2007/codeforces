#include<bits/stdc++.h>
#define ll long long
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
ll n,x;
void solve(){
	cin>>n;
	ll s,sum;
	cin>>s;sum=s;
	FOR(i,2,n){
		cin>>x;
		sum=sum+x;
		s=s^x;
	}
	cout<<"2\n"<<s<<' '<<sum+s<<'\n';
}
int main(){
	ll t;
	cin>>t;
	while(t--)solve();
	return 0;
}