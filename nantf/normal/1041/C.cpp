#include<bits/stdc++.h>
using namespace std;
int n,m,d,a[200020],t[200020],id[200020];
int ans[200020],al;
bool vis[200020];
struct state{
	int t,id;
	bool operator<(const state s)const{
		return t<s.t;
	}
}b[200020];
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++) scanf("%d",&b[i].t),b[i].id=i;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) t[i]=b[i].t,id[i]=b[i].id;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		al++;
		for(int cur=i;cur<=n;cur=lower_bound(t+1,t+n+1,t[cur]+d+1)-t){
			for(;cur<=n && vis[cur];cur++);
			if(cur>n) break;
			vis[cur]=true,ans[id[cur]]=al;
		}
	}
	printf("%d\n",al);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}