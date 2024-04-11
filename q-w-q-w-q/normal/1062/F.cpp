#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,op,x,y,d[300001],ans;
int q[300001],h,t,id[300001];
int f[300001],t1,t2,l[300001],r[300001],g[300001];
vector<int> in[300001],out[300001],qwq[300001];
inline bool cmpo(int i,int j){
	return id[i]<id[j];
}
inline bool cmpi(int i,int j){
	return id[i]>id[j];
}
int main(){
	cin>>n>>m,op=2;
	while(m--){
		scanf("%d%d",&x,&y);
		in[y].push_back(x),d[y]++;
		out[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!d[i]) q[++t]=i;
	while(h<t){
		x=q[++h],id[x]=h;
		for(int j:out[x]){
			d[j]--;
			if(!d[j]) q[++t]=j;
		}
	}
	for(int i=1;i<=n;i++){
		sort(out[i].begin(),out[i].end(),cmpo);
		sort(in[i].begin(),in[i].end(),cmpi);
	}
	for(int i=1,x;i<=n;i++){
		x=q[i];
		if(r[t1]<=i) g[i]=1;
		else if(r[t2]>i||f[t1]>i) g[i]=-1;
		if(out[x].size()){
			int tp=out[x][0];
			r[x]=id[tp];
			if(out[x].size()>1) f[tp]=max(f[tp],id[out[x][1]]);
			else f[tp]=1<<30;
		}
		else r[x]=1<<30;
		if(r[x]>r[t1]) t2=t1,t1=x;
		else if(r[x]>r[t2]) t2=x;
	}
	for(int i=0;i<=n;i++) f[i]=1<<30;
	l[0]=n+1,t1=t2=0;
	for(int i=n,x;i;i--){
		x=q[i];
		if(l[t1]>=i){
			if(g[i]==1||g[i]==0&&op==2) ans++;
		}
		else if(l[t2]>=i&&f[t1]>=i&&op==2&&g[i]==1) ans++;
		if(in[x].size()){
			int tp=in[x][0];
			l[x]=id[tp];
			if(in[x].size()>1) f[tp]=min(f[tp],id[in[x][1]]);
			else f[tp]=0;
		}
		else l[x]=0;
		if(l[x]<l[t1]) t2=t1,t1=x;
		else if(l[x]<l[t2]) t2=x;
	}
	cout<<ans;
}