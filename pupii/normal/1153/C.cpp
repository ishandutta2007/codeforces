#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
char s[300010];bool yes[300010];
int stk[300010],tp;
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi();scanf("%s",s+1);
	if(n&1)return puts(":("),0;
	for(int i=1;i<=n;++i)if(s[i]=='?')yes[i]=1,s[i]='(';
	int x=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='(')++x;
		else if(s[i]==')'){
			--x;
			if(x<0||(x==0&&i!=n))return puts(":("),0;
		}
	for(int i=n;i;--i)
		if(yes[i]&&x)
			x-=2,s[i]=')';
	x=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='(')++x;
		else if(s[i]==')'){
			--x;
			if(x<0||(x==0&&i!=n))return puts(":("),0;
		}
	if(x)return puts(":("),0;
	printf("%s",s+1);
	return 0;
}