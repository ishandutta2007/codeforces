#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 993244853
#define rg register
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
il int min(int a,int b){return a<b?a:b;}
char S[300][300];
int s[300][300];
int tot[300][300];
bool yes[300];
ll Hash[300],Base[300];
bool check(int x,int k){
	if(!x)return 1;
	if((x==(x&-x))&&k)return 1;
	return 0;
}
int r[300],R,R2;
int H[510];
main(){
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)scanf("%s",S[i]+1);
	Base[0]=1;for(int i=1;i<=26;++i)Base[i]=Base[i-1]*19260817%mod;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			s[i][j]=(1<<S[i][j]-'a')^s[i][j-1];
			tot[i][j]=(Base[S[i][j]-'a'+1]+tot[i][j-1])%mod;
		}
	ll ans=0;
	int N=n*2+1;
	for(rg int i=1;i<=m;++i)
		for(rg int j=i;j<=m;++j){
			for(rg int k=1;k<=n;++k)yes[k]=check(s[k][j]^s[k][i-1],(j-i+1)&1);
			for(rg int k=1;k<=n;++k)Hash[k]=(tot[k][j]-tot[k][i-1]+mod)%mod;
			for(rg int k=1;k<=n;++k)
				if(yes[k])H[k*2]=Hash[k];
				else H[k*2]=-1;
			R=0,R2=0;
			H[0]=-2,H[N+1]=-3;
			for(rg int i=1;i<=N;++i){
				r[i]=0;
				if(H[i]==-1)continue;
				if(i<=R)r[i]=min(R-i,r[R2-(i-R2)]);
				while(~H[i-r[i]]&&~H[i+r[i]]&&H[i-r[i]]==H[i+r[i]])++r[i];
				if(i+r[i]>R)R=i+r[i],R2=i;
			}
			for(int i=1;i<=N;++i)if(~H[i])ans+=std::max(0,r[i]/2);
		}
	printf("%lld\n",ans);
	return 0;
}