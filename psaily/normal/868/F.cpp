#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<iostream>
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

template<class T>inline void rd(T &x){
    x=0;char c;
    while(c=getchar(),c<48);
    do x=(x<<3)+(x<<1)+(c^48);
    while(c=getchar(),c>47);
}

const ll linf=2e18;
const int maxn=1e5+50;
const int maxk=25;

int n,k;
int A[maxn];
ll dp[maxk][maxn];

int s=1,t;
int cnt[maxn];
ll num_cnt;

void add(int u){
	num_cnt+=cnt[A[u]];
	cnt[A[u]]++;
}

void del(int u){
	//bug(num_cnt),bug(u),debug(A[u]);
	cnt[A[u]]--;
	num_cnt-=cnt[A[u]];
}

void upd(int l,int r){
	while(s>l)add(--s);
	while(t<r)add(++t);
	while(s<l)del(s++);
	while(t>r)del(t--);
}

void solve(int l,int r,int opt_l,int opt_r,int kth){
	if(l>r||opt_l>opt_r)return;
	
	int mid=(l+r)>>1,opt_pos=opt_l;
	
	for(int i=opt_l;i<=min(opt_r,mid-1);i++){
		upd(i+1,mid);
		if(dp[kth-1][i]+num_cnt<dp[kth][mid])
			dp[kth][mid]=dp[kth-1][i]+num_cnt,opt_pos=i;
	}
	
	solve(l,mid-1,opt_l,opt_pos,kth);
	solve(mid+1,r,opt_pos,opt_r,kth);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);

	for(int i=0;i<maxk;i++)for(int j=0;j<maxn;j++)dp[i][j]=linf;
	dp[0][0]=0;
	
	for(int j=1;j<=k;j++)solve(1,n,0,n-1,j);
	
	printf("%lld\n",dp[k][n]);
	
	return 0;
}