#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
#define inv2 499122177
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char map[20][100010];
int g[100010],A[1<<20],B[1<<20];
il vd FWTxor(int*A,int n,int t){
	for(int o=1;o<n;o<<=1)
		for(int*p=A;p!=A+n;p+=o<<1)
			for(int i=0;i<o;++i){
				int x=p[i],y=p[i+o];
				p[i]=(x+y)%mod,p[i+o]=(x-y+mod)%mod;
				if(!t)p[i]=1ll*p[i]*inv2%mod,p[i+o]=1ll*p[i+o]*inv2%mod;
			}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<1<<n;++i)B[i]=B[i^(i&-i)]+1;
	for(int i=0;i<1<<n;++i)B[i]=std::min(B[i],n-B[i]);
	for(int i=0;i<n;++i)scanf("%s",map[i]);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(map[i][j]=='1')
				g[j]|=1<<i;
	for(int i=0;i<m;++i)++A[g[i]];
	FWTxor(A,1<<n,1),FWTxor(B,1<<n,1);
	for(int i=0;i<1<<n;++i)A[i]=1ll*A[i]*B[i]%mod;
	FWTxor(A,1<<n,0);
	int ans=1e9;
	for(int i=0;i<1<<n;++i)ans=std::min(ans,A[i]);
	printf("%d\n",ans);
	return 0;
}