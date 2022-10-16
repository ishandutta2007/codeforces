#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
const int maxn=3005, Log=12, pot=(1<<Log);
typedef long long ll;
 
int n, k;
ll dp[maxn][maxn];
int sz[maxn];
int v[maxn][maxn];
ll s[maxn];
ll sol;
int tren;
 
void dinamika(int x){
	for(int i=k; i>=sz[x]; i--){
		dp[i][tren]=max(dp[i][tren-1], dp[i-sz[x]][tren-1]+s[x]);
	}
	for(int i=0; i<sz[x]; i++){
		dp[i][tren]=dp[i][tren-1];
	}
}
 
ll solve(int x){
	ll cur=0;
	ll sol=0;
	for(int i=k; i>=0; i--){
		sol=max(sol, cur+dp[i][tren]);
		cur+=v[x][k-i];
	}
	return sol;
}
 
vector < int > t[pot*2];
 
void update(int L, int D, int x, int l, int d, int val){
	if(L>=l && D<=d){
		t[x].push_back(val);
		return;
	}
	if((L+D)/2>=l){
		update(L, (L+D)/2, x*2, l, d, val);
	}
	if((L+D)/2+1<=d){
		update((L+D)/2+1, D, x*2+1, l, d, val);
	}
}
 
void rijesi(int x){
	for(int i=0; i<(int)t[x].size(); i++){
		tren++;
		dinamika(t[x][i]);
	}
	if(x<pot){
		rijesi(x*2);
		rijesi(x*2+1);
	}
	else{
		if(x-pot<n){
			sol=max(sol, solve(x-pot));
		}
	}
	tren-=t[x].size();
}
 
 
int main(){
	scanf("%d%d", &n, &k);
	int a;
	ll uk;
	for(int i=0; i<n; i++){
		scanf("%d", &sz[i]);
		uk=0;
		for(int j=0; j<sz[i]; j++){
			scanf("%d", &a);
			if(j<k){
				uk+=a;
				v[i][j]=a;
			}
		}
		s[i]=uk;
		sz[i]=min(sz[i], k);
	}
	for(int i=0; i<n; i++){
		if(i){
			update(0, pot-1, 1, 0, i-1, i);
		}
		if(i<n-1){
			update(0, pot-1, 1, i+1, pot-1, i);
		}
	}
	tren=0;
	rijesi(1);
	printf("%lld\n", sol);
	return 0;
}