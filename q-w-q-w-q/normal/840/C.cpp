#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cstdlib>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) ((x)&(-x))
#define sp(x,y) x^=y^=x^=y
using namespace std;
typedef long long ll;
bool o;
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,a[301],s[301],x,sum,cnt;
const ll mod=1e9+7;
ll f[301][301],c[301][301],ans;
int main(){
	rd(n);
	for(int i=1;i<=n;i++)
	rd(a[i]),s[i]=1;
	for(int i=1;i<=n;i++){
		if(!s[i]) continue;
		for(int j=i+1;j<=n;j++){
			if(!s[j]) continue;
			x=sqrt(1ll*a[i]*a[j]);
			if(1ll*x*x==1ll*a[i]*a[j]) s[j]=0,s[i]++;
		}
	}
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<i;j++)
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		c[i][i]=1;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		if(!s[i]) continue;
		sum+=s[i];
		cnt++;
		for(int k=1;k<=s[i];k++){
			x=s[i]-k;
			for(int j=0;j<=sum-cnt;j++){
				for(int l=mx(j-x,0);l<=sum-s[i]-cnt+1;l++){
					f[cnt][j]+=f[cnt-1][l]*c[s[i]-1][k-1]%mod*c[sum-s[i]+1-l][k+j-l-x]%mod*c[l][l+x-j]%mod;
					f[cnt][j]%=mod;
				}
			}
		}
	}
	ans=f[cnt][0];
	for(int i=1;i<=n;i++){
		if(!s[i]) continue;
		for(int j=2;j<=s[i];j++)
		ans*=j,ans%=mod;
	}
	wr(ans);
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (chh^45&&(chh<48||chh>57)) chh=gc();
      	if(chh==45)o=1,chh=gc();
        while(chh>47&&chh<58){
			x=(x<<1)+(x<<3)+(chh^48);
			chh=gc();
		}
      	if(o) x=-x;
 	}
template <typename _Tp>
    inline void wr(_Tp x){
        if(x<0) x=-x,putchar(45);
        if(x<10){
            putchar(x+48);
            return;
        }
        wr(x/10);
        putchar(x%10+48);
    }
template <typename _Tp>
	inline _Tp mx(_Tp x,_Tp y){
		return x>y?x:y;
	}
template <typename _Tp>
	inline _Tp mn(_Tp x,_Tp y){
		return x<y?x:y;
	}