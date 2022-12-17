#include<bits/stdc++.h>
using namespace std;
const int N=409,M=4e5+3;
char s[N];
int a[N],n0[N],n1[N],he[N],to[M],ne[M],t,n,st[N*2],tp;
bool b[N];
void add(int x,int y){ne[++t]=he[x],to[t]=y,he[x]=t;}
void ins(int x,int y){add(x,y),add(y>n?y-n:y+n,x>n?x-n:x+n);}
bool dfs(int x){
	if(b[x>n?x-n:x+n])return 0;
	b[x]=1,st[++tp]=x;
	for(int i=he[x];i;i=ne[i])if(!b[to[i]]&&!dfs(to[i]))return b[x]=0;
	return 1;
}
int main(){
	int m,l,i,j=1e9,k=1e9;
	bool f=0;
	char c1,c2;
	scanf("%s",s+1),l=strlen(s+1),n0[l+1]=n1[l+1]=j;
	for(i=l;i;--i){
		if(s[i]=='V')j=i;else k=i;
		n0[i]=j,n1[i]=k;// i 
	}
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d %c%d %c",&i,&c1,&j,&c2);
		ins(c1=='C'?i:i+n,c2=='C'?j:j+n);
	}
	scanf("%s",s+1);
	for(i=1;i<=n;++i)a[i]=s[i]-96;
	for(i=1;i<=n;++i){
		tp=0;
		if(f)a[i]=1;
		gg:;
		if(n0[a[i]]>1e8){//
			if(n1[a[i]]>1e8||b[i+n]||!dfs(i))return puts("-1"),0;
		}else if(n1[a[i]]>1e8){//
			if(b[i]||!dfs(i+n))return puts("-1"),0;
		}else if(!b[i]&&!b[i+n]){//
			if(n0[a[i]]>n1[a[i]]){//
				if(!dfs(i))if(f=1,!dfs(i+n))return puts("-1"),0;
			}else{
				if(!dfs(i+n))if(f=1,!dfs(i))return puts("-1"),0;
			}
		}else if(b[i]?n1[a[i]]>a[i]:n0[a[i]]>a[i])f=1;//
		if(!f){// f=0 
			for(j=i+1;j<=n;++j){
				if(b[j]){
					if(n1[a[j]]>1e8){
						f=1,++a[i];
						break;
					}
					if(n1[a[j]+1]<1e8)break;
				}else if(b[j+n]){
					if(n0[a[j]]>1e8){
						f=1,++a[i];
						break;
					}
					if(n0[a[j]+1]<1e8)break;
				}else if(n1[a[j]+1]<1e8||n0[a[j]+1]<1e8)break;
			}
			if(f){// f=0  dfs
				while(tp)b[st[tp--]]=0;
				goto gg;
			}
		}
	}
	for(i=1;i<=n;++i)putchar(96+(b[i]?n1[a[i]]:n0[a[i]]));
	return 0;
}