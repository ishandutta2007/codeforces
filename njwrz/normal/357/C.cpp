#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[1200005],ans[1200005];
int le[1200005],ri[1200005];
void put(int p,int l,int r,int x){
	if(le[p]>r||ri[p]<l)return ;
	if(le[p]>=l&&ri[p]<=r){
		v[p]=x;
		return;
	}
	if(v[p]){
		v[p*2]=v[p*2+1]=v[p];v[p]=0;
	}
	put(p*2,l,r,x);put(p*2+1,l,r,x);
}
void dfs(int p){
	if(le[p]==ri[p]){
		ans[le[p]]=v[p];return;
	}
	if(v[p]){
		v[p*2]=v[p*2+1]=v[p];
	}
	dfs(p*2+1);dfs(p*2);
}
int l1[300005],r1[300005],x1[300005];
int main(){
	scanf("%d%d",&n,&m);
	int l,r,x,t=1,ln=n;
	while(t<n)t*=2;
	n=t;
	for(int i=t;i<t*2;i++){
		le[i]=i-t+1;
		ri[i]=le[i];
	}
	for(int i=t-1;i>=1;i--){
		le[i]=le[i*2];
		ri[i]=ri[i*2+1];
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&l1[i],&r1[i],&x1[i]);
	}
	for(int i=m;i>=1;i--){
		if(x1[i]>l1[i])put(1,l1[i],x1[i]-1,x1[i]);
		if(r1[i]>x1[i])put(1,x1[i]+1,r1[i],x1[i]);
	}
	dfs(1);
	for(int i=1;i<=ln;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}