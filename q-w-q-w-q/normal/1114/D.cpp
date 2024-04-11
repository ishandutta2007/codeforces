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
int n,a[5001],ans,m1,m2,s;
bool ok;
int f[5001][5001],g[5001][5001];
int main(){
	rd(n);
	for(int i=1;i<=n;i++)
	rd(a[i]);
	for(int i=1;i<=n;i++) if(a[i]!=a[s]) a[++s]=a[i];
	n=s;
	/*for(int i=1;i<=5000;i++)
	f[1][i]=(a[1]!=i),g[1][i]=(a[1]==i);
	for(int i=2;i<=n;i++){
		for(int j=1;j<=5000;j++){
			f[i][j]=mn(f[i-1][a[i]]+(a[i]!=j),g[i-1][a[i]]+(f[i-1][j]!=g[i-1][a[i]])+(a[i]!=j));
			f[i][j]=mn(f[i][j],f[i-1][j]+(a[i]!=j));
		}
		m1=m2=inf;
		ok=0;
		for(int j=1;j<=5000&&!ok;j++){
			if(f[i][j]!=-1){
				if(f[i][j]<m1) m2=m1,m1=f[i][j];
				else if(f[i][j]==m1) ok=1;
				else if(f[i][j]<m2) m2=f[i][j];
			}
		}
		for(int j=1;j<=5000;j++){
			if(ok) g[i][j]=m1;
			else if(f[i][j]==m1) g[i][j]=m2;
			else g[i][j]=m1;
		}
	}
	ans=inf;
	for(int i=1;i<=5000;i++)
	if(f[n][i]^-1) ans=mn(ans,f[n][i]);
	wr(ans);*/
	for(int i=1;i<=n;i++)
	f[i][i]=0;
	for(int j=2;j<=n;j++){
		for(int i=j-1;i;i--){
			f[i][j]=mn(f[i+1][j]+1,f[i][j-1]+1);
			if(a[i]==a[j]) f[i][j]=mn(f[i][j],f[i+1][j-1]+1);
		}
	}
	wr(f[1][n]);
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