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
#include<ctime>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) (x)&(-x)
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
int n,k;
bool q[300001];
int x;
int f[300001],ne[300001];
int dp[300001];
inline void dfs(int i){
	if(f[i]==0){
		dp[i]=1;
		return;
	}
	int qwq=inf;
	for(int k=f[i];k;k=ne[k]){
		dfs(k);
		if(q[i]) qwq=mn(qwq,dp[k]);
		else dp[i]+=dp[k];
	}
	if(q[i]) dp[i]=qwq;
}
int main(){
	rd(n);
	k=n;
	for(int i=1;i<=n;i++)
	rd(q[i]);
	for(int i=2;i<=n;i++){
		rd(x);
		if(f[x]==0) k--;
		ne[i]=f[x];
		f[x]=i;
	}
	dfs(1);
	wr(k-dp[1]+1);
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