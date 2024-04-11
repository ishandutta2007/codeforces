#include<cstdio>
#include<cstring>
const int maxn=1000,mod=1000000007;
int n,k,l; char s[maxn+10];
int now[maxn+10],cnt,c[maxn+10][maxn+10],ans,f[maxn+10],g[maxn+10];
void prework(){
	c[0][0]=1;
	for(int i=1;i<=maxn;++i){
		c[i][0]=1;
		for(int j=1;j<=i;++j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
}
int main(){
	prework();
	scanf("%s%d",s+1,&k); int l=strlen(s+1);
	if(!k){
		printf("1"); return 0;
	}
	if(l==1){
		printf("0"); return 0;
	}
	for(int i=1;i<=l;++i)
		if(s[i]=='1'){
			for(int j=0;j<=l-i;++j) if(cnt+j)
				(now[cnt+j]+=c[l-i][j])%=mod;
			++cnt;
		}
	(now[cnt]+=1)%=mod; --now[1];
	for(int i=1;i<=maxn;++i){
		g[i]=g[i/2]+i%2; f[i]=i==1?0:f[g[i]]+1;
		if(f[i]==k-1) (ans+=now[i])%=mod;
	}
	printf("%d",ans); return 0;
}