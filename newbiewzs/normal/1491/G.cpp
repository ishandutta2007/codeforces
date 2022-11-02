#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=2e5+55;
vector<int>v[N];
int n,a[N],vis[N],top;
int st[N],head,qz;
void dfs(int u){
	if(vis[u])return ;
	vis[u]=1;
	v[top].push_back(u);
	dfs(a[u]);
}
vector<int>ansx,ansy;
void link(int x,int y){
	ansx.push_back(x);
	ansy.push_back(y);
}
void out(){
	printf("%d\n",ansx.size());
	for(int i=0;i<ansx.size();i++){
		printf("%d %d\n",ansx[i],ansy[i]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			top++;
			dfs(i);
		}
	}
	for(int i=1;i<=top;i+=2){
		if(i+1>top)break;
		int pre=i,suf=i+1;
		head=0;
		for(int k=0;k<v[pre].size();k++){
			st[++head]=v[pre][k];
		}
		for(int k=0;k<v[suf].size();k++){
			st[++head]=v[suf][k];
		}
		int x=v[pre].size(),y=head;
		link(st[1],st[y]);
		for(int k=2;k<=x;k++){
			link(st[k],st[y]);
		}
		for(int k=x+1;k<=y;k++){
			link(st[k],st[1]);
		}
		qz=st[y];
	}
	if(top%2==1){
		head=0;
		for(int k=0;k<v[top].size();k++){
			st[++head]=v[top][k];
		}
		if(head==1){
			out();
			return 0;
		}
		if(head==2){
			link(qz,st[1]);
			link(qz,st[2]);
			link(qz,st[1]);
			out();
			return 0;
		}
		for(int k=2;k<head;k++){
			link(st[k],st[head]);
		}
		link(st[1],st[head]);
		link(st[1],st[2]);
		link(st[2],st[head]);
	}
	out();
	return 0;
}