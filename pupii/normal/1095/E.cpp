#include<bits/stdc++.h>
#define il inline
#define vd void
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
char S[1000010];
int pre[1000010],suf[1000010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();scanf("%s",S+1);
	for(int i=1;i<=n;++i)
		if(pre[i-1]==-1)pre[i]=-1;
		else if(S[i]=='(')pre[i]=pre[i-1]+1;
		else if(pre[i-1])pre[i]=pre[i-1]-1;
		else pre[i]=-1;
	for(int i=n;i;--i)
		if(suf[i+1]==-1)suf[i]=-1;
		else if(S[i]==')')suf[i]=suf[i+1]+1;
		else if(suf[i+1])suf[i]=suf[i+1]-1;
		else suf[i]=-1;
	int ans=0;
	for(int i=1;i<=n;++i)if(~pre[i-1]&&~suf[i+1]&&(S[i]=='('?-1:1)+pre[i-1]-suf[i+1]==0)++ans;
	printf("%d\n",ans);
	return 0;
}