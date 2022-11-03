#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char _s[1000010],s[1000010];int n;
int ch[1000010][26],dif[1000010],anc[1000010],fail[1000010],len[1000010],cnt,f[1000010],g[1000010],lst;
il int newnode(int Len){++cnt,len[cnt]=Len;return cnt;}
il vd extend(int c,int n){
	int p=lst,q=ch[p][c];
	while(s[n-len[p]-1]!=s[n])p=fail[p];
	if(!ch[p][c]){
		int np=newnode(len[p]+2);q=fail[p];
		while(s[n-len[q]-1]!=s[n])q=fail[q];
		fail[np]=ch[q][c];ch[p][c]=np;
		dif[np]=len[np]-len[fail[np]];
		anc[np]=dif[np]==dif[fail[np]]?anc[fail[np]]:fail[np];
	}
	lst=ch[p][c];
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",_s+1);n=strlen(_s+1);
	for(int l=1,r=n,p=1;l<=r;++l,--r)s[p++]=_s[l],s[p++]=_s[r];
	cnt=lst=1;len[0]=0,len[1]=-1;fail[0]=fail[1]=1;
	f[0]=1;
	for(int i=1;i<=n;++i){
		extend(s[i]-'a',i);
		for(int j=lst;j;j=anc[j]){
			g[j]=f[i-len[anc[j]]-dif[j]];
			if(anc[j]^fail[j])g[j]=(g[j]+g[fail[j]])%mod;
			if(~i&1)f[i]=(f[i]+g[j])%mod;
		}
	}
	printf("%d\n",f[n]);
	return 0;
}