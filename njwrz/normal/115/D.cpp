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
char c[2005],s[2005];
bool is[2005];
ll dp1[2005][2005],dp2[2005][2005],mod=1e6+3;
signed main(){
	scanf("%s",c+1);
	int len,n=0;
	len=strlen(c+1);
	bool f=0;
	FOR(i,1,len){
		if(!isdigit(c[i])){
			if(f){
				s[++n]='1';
			}
			if(c[i]=='/'||c[i]=='*'){
				s[++n]='*';
			}else s[++n]='+';
			f=0;
		}else f=1;
	}
	if(f)s[++n]='1';
	FOR(i,1,n)is[i]=s[i]=='1';
	for(int i=n;i>=1;i--){
		if(s[i]=='1')dp1[i][i]=dp2[i][i]=1;
		FOR(j,i+1,n)if(is[j]){
			ll t=0;
			if(s[i]=='+')t=dp1[i+1][j];
			ll *d1=dp1[i]-1,*d2=dp2[j]+1; 
			FOR(k,i+1,j-1)if(!is[k])t+=1ll*d1[k]*d2[k];
//			FOR(k,i+1,j-1)if(!is[k])t+=1ll*dp1[i][k-1]*dp2[j][k+1];
			t%=mod;
			dp1[i][j]=dp2[j][i]=t;
		}
	}
	cout<<dp1[1][n];
	RE 0;
}