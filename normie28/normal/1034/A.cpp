#include <bits/stdc++.h>
using namespace std;
 
template <typename _Tp> inline _Tp read(_Tp&x){
	char c11=getchar();x=0;while(!isdigit(c11))c11=getchar();
	while(isdigit(c11))x=x*10+c11-'0',c11=getchar();return x;
}
const int N=15001000;
int f[N],pri[N/8],t[N/8],tp;
int n,a[301000];bool is[N];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline void calc(int x){
	int las=0;
	while(f[x]){
		if(f[x]!=las)++t[f[x]];
		las=f[x];x/=pri[f[x]];
	}
}
 
int main(){
	read(n);
	int G=read(a[1]);bool no=true;
	for(int i=2;i<=n;++i){
		read(a[i]),G=gcd(G,a[i]);
		if(a[i]!=a[i-1])no=false;
	}
	if(no){cout<<-1; return 0;}
	for(int i=1;i<=n;++i)
		a[i]/=G;
	for(int i=2;i<N;++i){
		if(!is[i])pri[++tp]=i,f[i]=tp;
		for(int j=1,k;j<=tp&&(k=i*pri[j])<N;++j){
			is[k]=true;f[k]=j;
			if(i%pri[j]==0)break;
		}
	}
	for(int i=1;i<=n;++i)
		calc(a[i]);
	int ans=0;
	for(int i=1;i<=tp;++i)
		ans=max(ans,t[i]);
	cout<<n-ans;
	return 0;
}