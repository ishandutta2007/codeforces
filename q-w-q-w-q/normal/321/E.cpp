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
int n,k,x,a[4001][4001];
int sl[4001][4001],sr[4001][4001],s[4001][4001];
int f[4001],g[4001];
int q[4001],h,t,d[4001];
inline int find(int x,int y){
	register int l=y+1,r=n,m,ans=n+1;
	while(l<=r){
		m=(l+r)>>1;
		if(g[y]+s[y+1][m]<=g[x]+s[x+1][m]) ans=m,r=m-1;
		else l=m+1;
	}
	return ans;
}
int main(){
	rd(n),rd(k);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	rd(a[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
		sl[i][j]=sl[i][j-1]+a[i][j];
		for(int j=i-1;j;j--)
		sr[i][j]=sr[i][j+1]+a[i][j];
	}
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	s[i][j]=s[i][j-1]+sr[j][i];
	for(int i=1;i<=n;i++) f[i]=g[i]=s[1][i];
	for(int tt=2;tt<=k;tt++){
		memset(d,0,sizeof(d));
		q[h=t=1]=1;
		for(int i=2;i<=tt;i++){
			f[i]=x=0;
			while(t>h&&(x=find(q[t],i))<=d[t]) t--;
			x=find(q[t],i);
			if(x!=n+1) q[++t]=i,d[t]=x;
		}
		for(int i=tt+1;i<=n;i++){
			while(h<t&&d[h+1]<=i) h++;
			f[i]=g[q[h]]+s[q[h]+1][i],x=0;
			while(t>h&&(x=find(q[t],i))<=d[t]) t--;
			x=find(q[t],i);
			if(x!=n+1) q[++t]=i,d[t]=x;
		}
		memcpy(g,f,sizeof(f));
	}
	cout<<f[n];
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