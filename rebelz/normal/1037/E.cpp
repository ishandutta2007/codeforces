#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int n,m,k,tot=0,now;
bool vis[200005];
int a[200005],b[200005],in[200005],v[400005],next[400005],flag[400005],h[200005],q[200005],ans[200005];

void addedge(int x,int y,int z){
	v[++tot]=y; next[tot]=h[x]; flag[tot]=z; h[x]=tot;
	v[++tot]=x; next[tot]=h[y]; flag[tot]=z; h[y]=tot;
}

void del(int x,int s){
	vis[x]=true,now--;
	for(int p=h[x];p;p=next[p])
		if(flag[p]<s&&!vis[v[p]]&&(--in[v[p]])<k)
			del(v[p],s);
}

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		addedge(a[i],b[i],i);
		in[a[i]]++,in[b[i]]++;
	}
	int front=0,rear=0;
	for(int i=1;i<=n;i++)
		if(in[i]<k)
			q[rear++]=i,vis[i]=true;
	now=n;
	while(front<rear){
		int t=q[front++];
		now--;
		for(int p=h[t];p;p=next[p])
			if((--in[v[p]])<k&&!vis[v[p]])
				q[rear++]=v[p],vis[v[p]]=true;
	}
	ans[m]=now;
	for(int i=m;i>=1;i--){
		if(!vis[a[i]]&&!vis[b[i]])
			in[a[i]]--,in[b[i]]--;
		if(!vis[a[i]]&&in[a[i]]<k)
			del(a[i],i);
		if(!vis[b[i]]&&in[b[i]]<k)
			del(b[i],i);
		ans[i-1]=now;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}