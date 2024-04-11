#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int q[300005];
char s[300005];

struct ACautomation{
	int cnt,top;
	int ch[300005][26],son[300005][26],fail[300005],fl[300005],val[300005],rt[105],siz[105];
	void getfail(int p){
		int front=0,rear=0;
		q[rear++]=p;
		while(front<rear){
			int t=q[front++];
			val[t]=fl[t]+val[fail[t]];
			for(int i=0;i<26;i++){
				if(ch[t][i]){
					q[rear++]=ch[t][i];
					son[t][i]=ch[t][i];
					if(t==p) fail[ch[t][i]]=p;
					else fail[ch[t][i]]=son[fail[t]][i]?son[fail[t]][i]:p;
				}
				else son[t][i]=t==p?p:son[fail[t]][i];
			}
		}
	}
	int merge(int x,int y){
		if(!x||!y) return x+y;
		fl[x]+=fl[y];
		for(int i=0;i<26;i++) ch[x][i]=merge(ch[x][i],ch[y][i]);
		return x;
	}
	void insert(char *t){
		rt[++top]=++cnt,siz[top]=1;
		int m=strlen(t+1),p=rt[top];
		for(int i=1;i<=m;i++){
			if(!ch[p][t[i]-'a']) ch[p][t[i]-'a']=++cnt;
			p=ch[p][t[i]-'a'];
		}
		fl[p]++;
		while(siz[top]==siz[top-1]) siz[top-1]+=siz[top],rt[top-1]=merge(rt[top-1],rt[top]),top--;
		getfail(rt[top]);
	}
	int query(char *t){
		int m=strlen(t+1),ret=0;
		for(int i=1;i<=top;i++) for(int p=rt[i],j=1;j<=m;j++) ret+=val[p=son[p][t[j]-'a']];
		return ret;
	}
}T1,T2;

int main(){
	n=readint();
	int opt;
	for(int i=1;i<=n;i++){
		opt=readint(); scanf("%s",s+1);
		if(opt==1) T1.insert(s);
		else if(opt==2) T2.insert(s);
		else printf("%d\n",T1.query(s)-T2.query(s));
		fflush(stdout);
	}
	return 0;
}