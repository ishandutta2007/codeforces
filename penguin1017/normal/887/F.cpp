#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=5e5+9;
const ll mod=998244353;
int sum[N];
void Set(int p,int val){
	for(int i=p;i<N;i+=lb(i))sum[i]+=val;
}
int Get(int p){
	int res=0;
	for(int i=p;i;i^=lb(i))res+=sum[i];
	return res; 
} 
pii a[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%d",&a[i].fi),a[i].se=i;
	sort(a,a+n);
	Set(1,1);
	Set(k+1,-1);
	int L=0,R=n,pos=n;
	rep(i,0,n){
		a[i].se=n-a[i].se;
		if(!Get(a[i].se)){
			if(pos==n)pos=i;
			if(L<a[i].se-k)L=a[i].se-k;
			if(R>a[i].se-1)R=a[i].se-1;
		}
		Set(a[i].se,1);
		Set(a[i].se+k+1,-1);
	}
	if(L>R){
		printf("NO\n");
		return 0;
	}
	if(pos==n){
		printf("YES\n");
		return 0;
	}
	memset(sum,0,sizeof sum);
	Set(1,1);
	Set(k+1,-1);
	rep(i,0,pos){
		if(Get(L)){
			printf("YES\n");
			return 0;
		}
		Set(a[i].se,1);
		Set(a[i].se+k+1,-1);
	}
	printf("NO\n");
}