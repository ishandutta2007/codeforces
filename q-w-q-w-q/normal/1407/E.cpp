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
int n,m,x,y,z;
int f[500001],to[500001],ne[500001];
bool v[500001],c[500001],u[500001],ok[500001],in[500001];
int q1[500001],q2[500001],s1,s2;
int sum[500001][2];
int ans;
inline void link(int x,int y,bool z,int k){
	to[k]=y;
	v[k]=z;
	ne[k]=f[x];
	f[x]=k;
}
int main(){
	rd(n),rd(m);
	for(int i=1;i<=m;i++){
		rd(x),rd(y),rd(z);
		link(y,x,z,i);
	}
	q1[s1=1]=n;
	ok[n]=u[n]=1;
	while(1){
		if(!s1){
			wr(-1),_e;
			for(int i=1;i<=n;i++)
			putchar(c[i]+'0');
			return 0;
		}
		s2=0;
		for(int i=1;i<=s1;i++){
			if(q1[i]==1){
				wr(ans),_e;
				for(int i=1;i<=n;i++) putchar(c[i]+'0');
				return 0;
			}
			for(int k=f[q1[i]];k;k=ne[k]){
				if(u[to[k]]) continue;
				sum[to[k]][v[k]]++;
				if(!in[to[k]]) q2[++s2]=to[k],in[to[k]]=1;
			}
		}
		s1=0;
		for(int i=1;i<=s2;i++){
			in[q2[i]]=0;
			if(ok[q2[i]]&&sum[q2[i]][c[q2[i]]]) q1[++s1]=q2[i],u[q2[i]]=1;
			if(ok[q2[i]]){
				sum[q2[i]][0]=sum[q2[i]][1]=0;
				continue;
			}
			if(sum[q2[i]][0]&&sum[q2[i]][1]){
				ok[q2[i]]=1;
				q1[++s1]=q2[i];
				u[q2[i]]=1;
				continue;
			}
			ok[q2[i]]=1;
			if(sum[q2[i]][0]) c[q2[i]]=1;
			sum[q2[i]][0]=sum[q2[i]][1]=0;
		}
		ans++;
	}
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