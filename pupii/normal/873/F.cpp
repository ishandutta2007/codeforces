#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[200010],F[200010];
int fa[400010],ch[400010][26],len[400100],cnt=1,lst=1;
int endpos[400010],s[400010],t[200010];
void extend(int c,int t){
	int p=lst,x=++cnt;endpos[x]=t;
	len[x]=len[p]+1;lst=x;
	while(p&&!ch[p][c])ch[p][c]=x,p=fa[p];
	if(!p)fa[x]=1;
	else{
		int q=ch[p][c];
		if(len[q]==len[p]+1)fa[x]=q;
		else{
			int nq=++cnt;memcpy(ch[nq],ch[q],4*26),fa[nq]=fa[q],len[nq]=len[p]+1;
			while(p&&ch[p][c]==q)ch[p][c]=nq,p=fa[p];
			fa[x]=fa[q]=nq;
		}
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();scanf("%s",S+1);scanf("%s",F+1);
	for(int i=1;i<=n;++i)extend(S[i]-'a',F[i]=='0');
	for(int i=1;i<=cnt;++i)++t[len[i]];
	for(int i=1;i<=n;++i)t[i]+=t[i-1];
	for(int i=cnt;i;--i)s[t[len[i]]--]=i;
	for(int i=cnt,x;i;--i)x=s[i],endpos[fa[x]]+=endpos[x];
	ll ans=0;
	for(int i=2;i<=cnt;++i)ans=std::max(ans,1ll*endpos[i]*len[i]);
	printf("%lld\n",ans);
	return 0;
}