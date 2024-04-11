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
const int f=1000000;
int n,m,up[501],s[501],tp,len;
char a[505],b[505];
int nt[501];
int sum;
namespace flow{
	int b,e;
	int ans,x,k,f[505],cur[505],to[200001],ne[200001],v[200001],c[200001];
	int q[1000001],h,t,d[505];
	bool in[505];
	inline void clear(){
		memset(f,-1,sizeof(f));
		k=0;
	}
	inline void link(int x,int y,int z,int ct){
		to[k]=y,v[k]=z,c[k]=ct,ne[k]=f[x],f[x]=k++;
		to[k]=x,v[k]=0,c[k]=-ct,ne[k]=f[y],f[y]=k++;
	}
	inline bool spfa(){
		memcpy(cur,f,sizeof(f));
		for(int i=1;i<=e;i++) d[i]=inf;
		d[b]=0,q[h=0,t=1]=b,in[b]=1;
		while(h!=t){
			in[x=q[++h]]=0;
			for(int k=f[x];k!=-1;k=ne[k]){
				if(v[k]&&d[to[k]]>d[x]+c[k]){
					d[to[k]]=d[x]+c[k];
					if(!in[to[k]]) in[q[++t]=to[k]]=1;
				}
			}
		}
		return d[e]!=inf;
	}
	inline int dfs(int i,int tp){
		if(i==e) return tp;
		in[i]=1;
		int gu=0,qwq;
		for(int k=cur[i];k!=-1;k=ne[k]){
			if(in[to[k]]||v[k]==0||d[to[k]]!=d[i]+c[k]) continue;
			qwq=dfs(to[k],mn(v[k],tp));
			gu+=qwq,tp-=qwq,v[k]-=qwq,v[k^1]+=qwq,ans+=c[k]*qwq;
			if(!tp){
				in[i]=0;
				cur[i]=k;
				return gu;
			}
		}
		in[i]=0,cur[i]=-1,d[i]=inf;
		return gu;
	}
	inline int min_cost_max_flow(){
		while(spfa()) dfs(b,1000000);
		return ans;
	}
}
int main(){
	scanf("%d%s%d",&n,a+1,&m);
	flow::b=0,flow::e=n+2,flow::ans=0;
	flow::clear();
	for(int i=1;i<=m;i++){
		scanf("%s%d",b+1,&tp);
		len=strlen(b+1);
		memset(nt,0,sizeof(nt));
		for(int j=2,k=0;j<=len;j++){
			while(k&&b[k+1]!=b[j]) k=nt[k];
			if(b[k+1]==b[j]) k++;
			nt[j]=k;
		}
		for(int j=1,k=0;j<=n;j++){
			while(k&&b[k+1]!=a[j]) k=nt[k];
			if(b[k+1]==a[j]) k++;
			if(k==len){
				sum+=tp;
				flow::link(j-len+1,j+1,1,tp);
				k=nt[k];
				s[j-len+1]++;
				s[j+1]--;
			}
		}
	}
	scanf("%d",&up[0]);
	flow::link(0,1,f,0);
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1];
		up[i]=up[i-1];
		if(s[i]<=up[i]) flow::link(i,i+1,f,0);
		else flow::link(i,i+1,f-s[i]+up[i],0);
	}
	flow::link(n+1,n+2,f,0);
	cout<<sum-flow::min_cost_max_flow();
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