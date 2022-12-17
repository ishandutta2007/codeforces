#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5;
int n,tl=0,hd=1;
char s[maxn];
int sz=2,lst=2,len[maxn],fa[maxn],nxt[maxn][26],fa2[maxn];
int get(int u,int x){
	while(x-len[u]-1<hd||s[x]!=s[x-len[u]-1]) u=fa[u];
	return u;
}
int cnt=0,d[maxn],p[maxn],p2[maxn],cur[maxn];
void upd(int u,int x){
	if(x>p[u]){
		p2[u]=p[u];
		p[u]=x;
	}
	else p2[u]=max(p2[u],x);
}
void extend(int x){
	int c=s[x]-'a',p=get(lst,x);
	if(!nxt[p][c]){
		int u=nxt[p][c]=++sz;
		cnt++;
		len[u]=len[p]+2;
		fa2[u]=p;
		if(p==1) fa[u]=2;
		else fa[u]=nxt[get(fa[p],x)][c];
		d[fa[u]]++;
	}
	upd(lst=nxt[p][c],x);
	if(!d[lst]) cur[x-len[lst]+1]=lst;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	len[1]=-1;
	fa[2]=1;
	while(n--){
		char opt[5];
		scanf("%s",opt);
		if(opt[1]=='u'){
			scanf("%s",s+(++tl));
			extend(tl);
		}
		else{
			if(len[lst]==tl-hd+1) lst=fa[lst];
			int u=cur[hd];
			if(u&&p2[u]-len[u]+1<hd){
				int v=fa[u];
				if(v>2){
					upd(v,p[u]);
					upd(v,p2[u]);
					if(!--d[v]&&len[v]>len[cur[p[v]-len[v]+1]])
						cur[p[v]-len[v]+1]=v;
				}
				nxt[fa2[u]][s[hd]-'a']=0;
				cnt--;
			}
			hd++;
		}
		printf("%d\n",cnt);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}