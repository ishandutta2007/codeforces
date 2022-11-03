#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
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
int f[100010][101],S[100010],cnt[100010][101];
int A[100010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),len=gi();
	if(len==1)return puts("0"),0;
	for(int i=1;i<=n;++i)A[i]=gi();
	S[0]=1;
	if(A[1]==-1)for(int i=1;i<=m;++i)f[1][i]=1,++S[1];
	else f[1][A[1]]=1,S[1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cnt[i][j]=cnt[i-1][j]+(A[i]==-1||A[i]==j);
	for(int i=2;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(A[i]!=-1&&A[i]!=j)continue;
			if(i<len||(cnt[i][j]-cnt[i-len][j])<len)f[i][j]=S[i-1];
			else{
				f[i][j]=(S[i-1]-S[i-len]+f[i-len][j])%mod;
				if(f[i][j]<0)f[i][j]+=mod;
			}
			S[i]=(S[i]+f[i][j])%mod;
		}
	}
	printf("%d\n",S[n]);
	return 0;
}