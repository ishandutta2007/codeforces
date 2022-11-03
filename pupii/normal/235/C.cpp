#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[1000010],T[1000010];
int trans[2000010][26],slink[2000010],len[2000010],leaf[2000010],lst=1,cnt=1;
int st[2000010],tot[2000010],tt[2000010];
int t[2000010],tm;
void extend(int ch,int i){
	int p=lst,np=++cnt;len[np]=len[lst]+1;leaf[i]=np;tot[np]=1;lst=np;
	while(p&&!trans[p][ch])trans[p][ch]=np,p=slink[p];
	if(!p)slink[np]=1;
	else{
		int q=trans[p][ch];
		if(len[q]==len[p]+1)slink[np]=q;
		else{
			int nq=++cnt;len[nq]=len[p]+1;slink[nq]=slink[q];
			memcpy(trans[nq],trans[q],sizeof trans[q]);
			while(p&&trans[p][ch]==q)trans[p][ch]=nq,p=slink[p];
			slink[np]=slink[q]=nq;
		}
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);int n=strlen(S+1);
	for(int i=1;i<=n;++i)extend(S[i]-='a',i);
	for(int i=1;i<=cnt;++i)++tt[len[i]];
	for(int i=1;i<=n;++i)tt[i]+=tt[i-1];
	for(int i=cnt;i;--i)st[tt[len[i]]--]=i;
	for(int _=cnt,x;_;--_)x=st[_],tot[slink[x]]+=tot[x];
	int q=gi();
	while(q--){
		scanf("%s",T+1);int m=strlen(T+1),x=1,le=0;ll ans=0;
		for(int i=1;i<=m;++i){
			T[i]-='a';
			while(x&&!trans[x][T[i]])x=slink[x],le=len[x];
			x=trans[x][T[i]];++le;if(!x){ans=-1;break;}
		}
		if(ans==-1){puts("0");continue;}
		++tm;
		for(int i=1;i<=m;++i){
			if(le>=m){
				if(t[x]<tm)ans+=tot[x],t[x]=tm;
				if(le)--le;
				if(x>1&&len[slink[x]]==le)x=slink[x];
			}
			while(x>1&&(!trans[x][T[i]]))x=slink[x],le=len[x];
			x=trans[x][T[i]];++le;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//