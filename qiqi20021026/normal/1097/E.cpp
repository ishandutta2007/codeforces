#include<bits/stdc++.h>

using namespace std;

#define N 120000

int n,k,cnt,a[N],f[N],bit[N];
bool vis[N];
vector<int> out[N];

void mdf(int x,int k){
	for (;x<=n;x+=x&(-x)) bit[x]=max(bit[x],k);
}

int qry(int x){
	int ret=0;
	for (;x;x-=x&(-x)) ret=max(ret,bit[x]);
	return ret;
}

void calc(){
	int m=0;
	for (int i=1;i<=n;++i){
		bit[i]=0;
		m+=!vis[i];
	}
	for (k=1;k*(k+1)/2<m;++k);
	if (!m) return;
	int mx=0;
	for (int i=1;i<=n;++i){
		if (vis[i]) continue;
		f[i]=qry(a[i])+1;
		mdf(a[i],f[i]);
		if (f[i]>f[mx]) mx=i;
	}
	if (f[mx]>=k){
		int now=f[mx];
		++cnt;
		for (int i=mx;i;--i){
			if (vis[i]) continue;
			if (f[i]==now){
				vis[i]=1;
				out[cnt].push_back(i);
				--now;
			}
		}
		reverse(out[cnt].begin(),out[cnt].end());
		calc();
	}
	else{
		k=f[mx];
		for (int i=1;i<=n;++i){
			if (vis[i]) continue;
			for (int j=1;j<=k;++j){
				if (out[cnt+j].empty()||a[i]<a[*out[cnt+j].rbegin()]){
					out[cnt+j].push_back(i);
					break;
				}
			}
		}
		cnt+=k;
		return;
	}
}

void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
		vis[i]=0;
	}
	cnt=0;
	calc();
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;++i){
		printf("%d",(int)out[i].size());
		for (int j:out[i]) printf(" %d",a[j]);
		puts("");
		out[i].clear();
	}
}

int main(){
	int T; scanf("%d",&T);
	while (T--) solve();
	
	return 0;
}