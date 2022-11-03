#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[510];
int ls[180],rs[180],w[180],cnt;
int dp[170][65569],A[65539],B[65539];
int divide(int l,int r){
	int x=++cnt;
	if(l==r){w[x]=S[l];return cnt;}
	int p=l+1,c=1;
	while(c){
		if(S[p]=='(')++c;
		else if(S[p]==')')--c;
		++p;
	}
	w[x]=S[p];
	ls[x]=divide(l+1,p-2);
	rs[x]=divide(p+2,r-1);
	return x;
}
char _[10]="ABCDabcd";
void add(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
void sub(int&a,int b){a=a>=b?a-b:a-b+mod;}
void FWTand(int*A,int n,bool t){
	for(int o=1;o<n;o<<=1)
		for(int*p=A;p!=A+n;p+=o<<1)
			for(int i=0;i<o;++i){
				if(t)add(p[i],p[i+o]);
				else sub(p[i],p[i+o]);
			}
}
void FWTor(int*A,int n,bool t){
	for(int o=1;o<n;o<<=1)
		for(int*p=A;p!=A+n;p+=o<<1)
			for(int i=0;i<o;++i){
				if(t)add(p[i+o],p[i]);
				else sub(p[i+o],p[i]);
			}
}
void dfs(int x){
	if(!ls[x]){
		for(int j=0,k=0;j<8;++j,k=(k+1)&3){
			if(w[x]!='?'&&w[x]!=_[j])continue;
			int S=0;
			for(int s=0;s<16;++s){
				if((( s>>k)&1)&&j< 4)S|=1<<s;
				if(((~s>>k)&1)&&j>=4)S|=1<<s;
			}
			add(dp[x][S],1);
		}
		return;
	}
	dfs(ls[x]),dfs(rs[x]);
	if(w[x]!='&'){
		memcpy(A,dp[ls[x]],sizeof A);
		memcpy(B,dp[rs[x]],sizeof B);
		FWTor(A,1<<16,1);FWTor(B,1<<16,1);
		for(int i=0;i<1<<16;++i)A[i]=1ll*A[i]*B[i]%mod;
		FWTor(A,1<<16,0);
		for(int i=0;i<1<<16;++i)add(dp[x][i],A[i]);
	}
	if(w[x]!='|'){
		memcpy(A,dp[ls[x]],sizeof A);
		memcpy(B,dp[rs[x]],sizeof B);
		FWTand(A,1<<16,1);FWTand(B,1<<16,1);
		for(int i=0;i<1<<16;++i)A[i]=1ll*A[i]*B[i]%mod;
		FWTand(A,1<<16,0);
		for(int i=0;i<1<<16;++i)add(dp[x][i],A[i]);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);
	divide(1,strlen(S+1));
	dfs(1);
	int m=gi(),a,b,c,d,conf=0,S=0,res;
	while(m--){
		a=gi(),b=gi(),c=gi(),d=gi();
		res=a|(b<<1)|(c<<2)|(d<<3);
		conf|=1<<res;S|=gi()<<res;
	}
	int ans=0;
	for(int i=0;i<1<<16;++i)if((i&conf)==S)add(ans,dp[1][i]);
	printf("%d\n",ans);
	return 0;
}