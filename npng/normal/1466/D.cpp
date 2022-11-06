#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=100000;
int deg[Maxn+5];
int n;
int w[Maxn+5];
int lis[Maxn+5],lis_len;
bool cmp(int p,int q){
	return p>q;
}
void solve(){
	scanf("%d",&n);
	lis_len=0;
	for(int i=1;i<=n;i++){
		deg[i]=0;
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		sum+=w[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++,deg[v]++;
	}
	for(int i=1;i<=n;i++){
		deg[i]--;
		while(deg[i]--){
			lis[++lis_len]=w[i];
		}
	}
	sort(lis+1,lis+1+lis_len,cmp);
	for(int i=1;i<n;i++){
		printf("%lld ",sum);
		sum+=lis[i];
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}