#include<bits/stdc++.h>

using namespace std;

#define N 7000
#define LL long long

LL n,m,p,t,a[N],b[N],f[N];
map<LL,LL> vis,num;

void solve(){
	scanf("%lld",&n);
	m=0;
	for (LL i=1;i*i<=n;++i)
		if (n%i==0){
			a[++m]=i;
			if (n/i!=i) a[++m]=n/i;
		}
	sort(a+1,a+m+1);
	p=0; vis.clear(); num.clear();
	for (LL i=1;i<=m;++i){
		num[a[i]]=i;
		LL x=a[i]-1; bool fl=1;
		for (LL j=2;j*j<=x;++j)
			if (x%j==0){
				fl=0;
				while (x%j==0) x/=j;
				if (x==1&&!vis[j]){vis[j]=1; b[++p]=j;}
				break;
			}
		if (fl&&x>1&&!vis[x]){vis[x]=1; b[++p]=x;}
	}
	sort(b+1,b+p+1);
	memset(f,0,sizeof f); f[m]=1;
	for (LL i=p;i;--i)
		for (LL j=1;j<=m;++j){
			if (!f[j]) continue;
			for (LL k=b[i];k<a[j];k*=b[i]){
				if (a[j]%(k+1)==0){
					LL x=a[j]/(k+1);
					f[num[x]]+=f[j];
				}
			}
		}
	printf("%lld\n",f[1]);
}

int main(){
    solve();
	
	return 0;
}