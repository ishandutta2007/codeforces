#include<bits/stdc++.h>
using namespace std;
const int maxn=5555,mod=1000000007,lim=65536;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,dp[255][lim],m,a[16],b[16],with[maxn],stk[maxn],tp,cnt,ch[maxn][2],fa[maxn],id[maxn],rt,p[lim],q[lim];
char s[maxn],val[maxn];
bool op[maxn];
void FMT_pre(int *A){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) A[j+k]=(A[j+k]+A[i+j+k])%mod;
}
void IFMT_pre(int *A){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) A[j+k]=(A[j+k]-A[i+j+k]+mod)%mod;
}
void FMT_suf(int *A){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) A[i+j+k]=(A[i+j+k]+A[j+k])%mod;
}
void IFMT_suf(int *A){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) A[i+j+k]=(A[i+j+k]-A[j+k]+mod)%mod;
}
void dfs(int now){
	if(ch[now][0]) dfs(ch[now][0]);
	if(ch[now][1]) dfs(ch[now][1]);
	if(!op[now]){
		switch(val[now]){
			case 'A':dp[now][65280]=1;break;
			case 'B':dp[now][61680]=1;break;
			case 'C':dp[now][52428]=1;break;
			case 'D':dp[now][43690]=1;break;
			case 'a':dp[now][255]=1;break;
			case 'b':dp[now][3855]=1;break;
			case 'c':dp[now][13107]=1;break;
			case 'd':dp[now][21845]=1;break;
			case '?':
				dp[now][65280]=dp[now][61680]=dp[now][52428]=dp[now][43690]=
				dp[now][255]=dp[now][3855]=dp[now][13107]=dp[now][21845]=1;
		}
	}
	else{
		if(val[now]!='|'){
			FOR(i,0,lim-1) p[i]=dp[ch[now][0]][i],q[i]=dp[ch[now][1]][i];
			FMT_pre(p);FMT_pre(q);
			FOR(i,0,lim-1) p[i]=1ll*p[i]*q[i]%mod;
			IFMT_pre(p);
			FOR(i,0,lim-1) dp[now][i]=(dp[now][i]+p[i])%mod;
		}
		if(val[now]!='&'){
			FOR(i,0,lim-1) p[i]=dp[ch[now][0]][i],q[i]=dp[ch[now][1]][i];
			FMT_suf(p);FMT_suf(q);
			FOR(i,0,lim-1) p[i]=1ll*p[i]*q[i]%mod;
			IFMT_suf(p);
			FOR(i,0,lim-1) dp[now][i]=(dp[now][i]+p[i])%mod;
		}
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	m=read();
	FOR(i,0,m-1){
		FOR(j,0,3) a[i]=2*a[i]+read();
		b[i]=read();
	}
	FOR(i,1,n){
		if(s[i]=='(') stk[++tp]=i;
		else if(s[i]==')') with[i]=stk[tp],with[stk[tp]]=i,tp--;
	}
	FOR(i,1,n) if(s[i]!='(' && s[i]!=')'){
		id[i]=++cnt;
		val[cnt]=s[i];
		int j=i;
		while(j<=n && (s[j]!=')' || with[j]>i)) j++;
		id[j]=id[with[j]]=cnt;
	}
	FOR(i,1,n) if(s[i]!='(' && s[i]!=')'){
		if(s[i-1]==')' && s[i+1]=='('){
			fa[id[i-1]]=fa[id[i+1]]=id[i];
			ch[id[i]][0]=id[i-1];
			ch[id[i]][1]=id[i+1];
			op[id[i]]=1;
		}
	}
	FOR(i,1,cnt) if(!fa[i]) assert(!rt),rt=i;
	dfs(rt);
	int ans=0;
	FOR(i,0,lim-1){
		bool flag=true;
		FOR(j,0,m-1) if(((i>>a[j])&1)!=b[j]) flag=false;
		if(flag) ans=(ans+dp[rt][i])%mod;
	}
	printf("%d\n",ans);
}
// Coming soon 2020.5.11