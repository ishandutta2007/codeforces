#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n;
ll a[MN];
int b[60];
vector<int>g[125];
int d[125];
int fu,fv;
void bfs(int s){
	static int q[500];
	int l,r;
	d[s]=0,q[l=r=1]=s;
	while(l<=r){
		int u=q[l++];
		for(auto v:g[u]){
			if(d[v]!=0x3f3f3f3f||(u==fu&&v==fv)||(u==fv&&v==fu))continue;
			d[v]=d[u]+1;
			q[++r]=v;
		}
	}
}
int main(){
	int ans=0x3f3f3f3f;
	scanf("%d",&n);
	F(i,1,n)scanf("%lld",a+i);
	F(i,1,n)F(j,0,59)if(a[i]>>j&1)++b[j];
	F(j,0,59)if(b[j]>=3)return puts("3"),0;
	sort(a+1,a+n+1,[](ll i,ll j){return i>j;});
	while(n&&!a[n])--n;
//	debug("n=%d\n",n);
	if(n>120)while(1);
	F(i,2,n)F(j,1,i-1)if(a[i]&a[j])g[i].pb(j),g[j].pb(i);
	F(i,2,n)F(j,1,i-1)if(a[i]&a[j]){
		fu=i,fv=j;
		memset(d,0x3f,sizeof d);
		bfs(i);
		if(d[j]!=0x3f3f3f3f)ans=min(ans,d[j]+1);
	}
	printf("%d\n",ans>n?-1:ans);
	return 0;
}

/*
8
0 0 0 0 0 3 6 5


*/