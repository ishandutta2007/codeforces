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
char s[1000005],c[1000005]; 
signed main(){
	int n;scanf("%d",&n);
	getchar();
	FOR(i,1,n)s[i]=getchar();
	getchar();
	FOR(i,1,n)c[i]=getchar();
	int st=-1;
	FOR(i,1,n){
		if(s[i]!=c[i]){
			st=i;break;
		}
	}
	if(st==1){
		FOR(i,1,n)putchar('1');
	}else {
		if(st==-1){
			FOR(i,1,n)putchar(s[i]);
		}else{
			FOR(i,st+1,n){
				if(s[i]!='1'||c[i]!='0'){
					c[n]='1';break;
				}
			}
			FOR(i,1,n)putchar(c[i]);
		}
	}
	RE 0;
}