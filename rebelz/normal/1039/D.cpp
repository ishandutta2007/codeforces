#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,ans,cnt;
int v[200005],nxt[200005],h[100005],max1[100005],max2[100005],out[100005],f[100005],dfn[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

int work(int k){
	ans=0;
	memset(max1,0,sizeof(max1));
	memset(max2,0,sizeof(max2));
	for(int i=n;i>=1;i--){
		int u=dfn[i];
		if(max1[u]+max2[u]>=k) ans++;
		else if(max1[u]+1>max1[f[u]]) max2[f[u]]=max1[f[u]],max1[f[u]]=max1[u]+1;
		else if(max1[u]+1>max2[f[u]]) max2[f[u]]=max1[u]+1;
	}
	return ans;
}

void dfs(int u){
	dfn[++cnt]=u;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]!=f[u]){
			f[v[p]]=u;
			dfs(v[p]);
		}
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dfs(1);
	int tmp=min(1250,n);
	for(int i=1;i<=tmp;i++) out[i]=work(i-1);
	int now=n,l,r,ret;
	for(int i=0;i<=n/tmp;i++){
		l=tmp+1,r=now,ret=now+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(work(mid-1)<=i) ret=mid,r=mid-1;
			else l=mid+1;
		}
		for(int j=ret;j<=now;j++) out[j]=i;
		now=ret-1;
	}
	for(int i=1;i<=n;i++) printf("%d\n",out[i]);
	return 0;
}