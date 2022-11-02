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
int a[30]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int cnt=0;
	FOR(i,1,n)cnt+=a[i]&1;
	if(n==1){
		cout<<a[1]<<'\n';
		FOR(i,1,a[1])cout<<'a';
	}else if(cnt>1){
		cout<<0<<'\n';
		FOR(i,1,n){
			FOR(j,1,a[i])cout<<(char)(i+'a'-1);
		} 
	}else{
		string s;
		int t=a[1];
		FOR(i,2,n){
			t=__gcd(t,a[i]);
		}
		FOR(i,1,n)a[i]/=t;
		cnt=0;
		FOR(i,1,n)cnt+=a[i]&1;
		if(cnt>1){
			if(t&1){
				cout<<1<<'\n';
				FOR(i,1,n)a[i]*=t;
				FOR(i,1,n){
					FOR(j,1,a[i]/2)s+=(char)(i+'a'-1);
				}
				FOR(i,1,n){
					if(a[i]&1)s+=(i+'a'-1);
				} 
				for(int i=n;i>=1;i--){
					FOR(j,1,a[i]/2)s+=(char)(i+'a'-1);
				}
				cout<<s;RE 0;
			}
			FOR(i,1,n)a[i]*=2;
			t/=2;
			cout<<t*2<<'\n';
		}else cout<<t<<'\n';
		FOR(i,1,n){
			FOR(j,1,a[i]/2)s+=(char)(i+'a'-1);
		}
		FOR(i,1,n){
			if(a[i]&1)s+=(i+'a'-1);
		} 
		for(int i=n;i>=1;i--){
			FOR(j,1,a[i]/2)s+=(char)(i+'a'-1);
		}
		FOR(i,1,t)cout<<s;
	}
	RE 0;
}