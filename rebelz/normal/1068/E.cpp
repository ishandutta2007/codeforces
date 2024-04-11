#include<bits/stdc++.h>

using namespace std;

int n,k,tot=0;
int a[100005],b[100005],du[100005],v[200005],nxt[200005],h[100005],dep[100005],siz[100005];
bool flag[100005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

bool dfs(int u,int fa){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa)
			continue;
		dep[v[p]]=dep[u]+1;
		if(!dfs(v[p],u))
			return false;
		siz[u]++;
	}
	if(siz[u]>0&&siz[u]<3)
		return false;
	else
		return true;
}

int main(){
	n=readint(); k=readint();
	int tmp=k;
	for(int i=1;i<=n-1;i++){
		a[i]=readint(); b[i]=readint();
		du[a[i]]++,du[b[i]]++;
	}
	int cnt=0;
	while(cnt<n-1){
		for(int i=1;i<=n;i++){
			if(du[i]==2){
				cout<<"No"<<endl;
				return 0;
			}
			else if(du[i]==1&&!flag[i])
				flag[i]=true,cnt++;
		}
		k--;
		if(cnt>=n-1)
			break;
		memset(du,0,sizeof(du));
		for(int i=1;i<=n-1;i++)
			if(!flag[a[i]]&&!flag[b[i]])
				du[a[i]]++,du[b[i]]++;
	}
	if(cnt!=n-1||k!=0){
		cout<<"No"<<endl;
		return 0;
	}
	int x;
	for(int i=1;i<=n;i++)
		if(!flag[i])
			x=i;
	for(int i=1;i<=n-1;i++)
		addedge(a[i],b[i]);
	dep[x]=1;
	if(!dfs(x,-1)){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(dep[i]<=tmp&&siz[i]==0){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}