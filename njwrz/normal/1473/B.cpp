/*

DP





ll int
 dp 










*/
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
char a[25],b[25],c[405];
void solve(){
	scanf("%s%s",a+1,b+1);
	int la,lb;
	la=strlen(a+1);
	lb=strlen(b+1);
	int len=la/__gcd(la,lb)*lb;
	FOR(i,1,len/la){
		FOR(j,1,la)c[(i-1)*la+j]=a[j];
	}
	FOR(i,1,len/lb){
		FOR(j,1,lb){
			if(c[(i-1)*lb+j]!=b[j]){
				puts("-1");RE;
			}
		}
	}
	FOR(i,1,len){
		cout<<c[i];
	}
	cout<<'\n';
}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}