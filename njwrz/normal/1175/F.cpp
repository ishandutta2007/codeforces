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
int n,a[300005];
unsigned long long p[300005],t[300005],s[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	srand(time(0));
	FOR(i,1,n)t[i]=1ull*rand()*rand()<<10;
	FOR(i,1,n){
		p[i]=t[i]^p[i-1];
		s[i]=s[i-1]^t[a[i]];
	}
	int cnt=0;
	FOR(i,1,n){
		if(a[i]==1){
			int l=1,r=n;
			FOR(j,i+1,n){
				if(a[j]==1){
					r=j-1;break;
				}
			}
			for(int j=i-1;j>=1;j--){
				if(a[j]==1){
					l=j+1;break;
				}
			}
			int maxi=0;
			FOR(j,i,r){
				gmax(maxi,a[j]);
				if(j-maxi+1>=l){
					cnt+=(s[j]^s[j-maxi])==p[maxi];
				}
			}
			maxi=1;
			for(int j=i-1;j>=l;j--){
				gmax(maxi,a[j]);
				if(j+maxi-1<=r){
					cnt+=(s[j+maxi-1]^s[j-1])==p[maxi]; 
				}
			}
		}
	}
	cout<<cnt;
	RE 0;
}