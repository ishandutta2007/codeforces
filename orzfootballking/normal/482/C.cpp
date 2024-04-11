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
#define ld long double
using namespace std;
int it[1<<20];
ld used[1<<20];
char c[55][21];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int m;
	rep(i,0,n){
		string s;
		cin>>s;m=s.size();
		rep(j,0,s.size())c[i][j]=s[j];
	}
	rep(i,0,n){
		rep(j,i+1,n){
			int same=0;
			rep(k,0,m){
				if(c[i][k]==c[j][k]){
					same|=(1<<k);
				}
			}
			it[same]|=(1ll<<i)|(1ll<<j);
		}
	}
	for(int mask=(1<<m)-1;mask>=1;mask--){
		rep(i,0,m)if(mask&(1<<i)){
			it[mask^(1<<i)]|=it[mask]; 
		}
	}
	used[0]=1.0/n;
	double ans=0;
	rep(mask,0,(1<<m)){
		int p1,p2;
		p1=p2=0;
		rep(i,0,m)if(!(mask&(1<<i)))p1++;
		rep(i,0,n)if(it[mask]&(1ll<<i))p2++;
		rep(i,0,m)if(!(mask&(1<<i))){
			used[mask|(1<<i)]+=used[mask]/p1;
		}
		ans=ans+used[mask]*p2;
	} 
	printf("%.10f",ans);
	RE 0;
}