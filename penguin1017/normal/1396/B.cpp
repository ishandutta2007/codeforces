#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
int a[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int maxn=0,sum=0;
		rep(i,1,n+1){
			scanf("%d",&a[i]);
			maxn=max(maxn,a[i]);
			sum+=a[i];
		} 
		if(n==1){
			printf("T\n");
			continue;
		}
		if(maxn>sum/2){
			printf("T\n");
			continue;
		}
		if(sum&1)printf("T\n");
		else printf("HL\n");
	}
}