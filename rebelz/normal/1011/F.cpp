#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,tot=0;
int t[1000005],b[1000005],v[2000005],next[2000005],h[1000005],d[1000005][2],num[1000005];
char ch[1000005];

void addedge(int x,int y){
	v[++tot]=y; next[tot]=h[x]; h[x]=tot;
	v[++tot]=x; next[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	if(ch[u]=='A')
		num[u]=1;
	for(int p=h[u];p;p=next[p]){
		if(v[p]==fa)
			continue;
		dfs1(v[p],u);
		if(ch[u]=='N')
			num[u]=num[v[p]]^1;
		else if(ch[u]=='A')
			num[u]&=num[v[p]];
		else if(ch[u]=='X')
			num[u]^=num[v[p]];
		else if(ch[u]=='O')
			num[u]|=num[v[p]];
	}
	if(ch[u]=='I')
		num[u]=t[u];
}

void dfs2(int u,int fa){
	for(int p=h[u];p;p=next[p]){
		if(v[p]==fa)
			continue;
		if(ch[u]=='N')
			d[v[p]][0]=d[u][1],d[v[p]][1]=d[u][0];
		else if(ch[u]=='A')
			d[v[p]][0]=d[u][0],d[v[p]][1]=d[u][num[b[v[p]]]];
		else if(ch[u]=='X')
			d[v[p]][0]=d[u][num[b[v[p]]]],d[v[p]][1]=d[u][num[b[v[p]]]^1];
		else if(ch[u]=='O')
			d[v[p]][0]=d[u][num[b[v[p]]]],d[v[p]][1]=d[u][1];
		dfs2(v[p],u);
	}
}

int main(){
	cin>>n;
	char s[5];
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>s>>x;
		ch[i]=s[0];
		if(s[0]=='I')
			t[i]=x;
		else if(s[0]=='N')
			addedge(i,x);
		else if(s[0]=='A'){
			cin>>y;
			addedge(i,x);
			addedge(i,y);
			b[x]=y,b[y]=x;
		}
		else if(s[0]=='X'){
			cin>>y;
			addedge(i,x);
			addedge(i,y);
			b[x]=y,b[y]=x;
		}
		else if(s[0]=='O'){
			cin>>y;
			addedge(i,x);
			addedge(i,y);
			b[x]=y,b[y]=x;
		}
	}
	dfs1(1,-1);
	d[1][0]=0,d[1][1]=1;
	dfs2(1,-1);
	for(int i=1;i<=n;i++)
		if(ch[i]=='I')
			cout<<d[i][t[i]^1];
	cout<<endl;
	return 0;
}