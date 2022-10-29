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
const int N=1e5+9;
const ll mod=998244353;
pii p[N],p2[N];
int main(){
	int n;
	ll x=0,y=0;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d%d",&p[i].fi,&p[i].se);
		x+=p[i].fi;y+=p[i].se;
	}
	x<<=1,y<<=1;
	if(x%n||y%n){
		printf("NO\n");
		return 0;
	}
	x/=n,y/=n;
	sort(p,p+n);
	rep(i,0,n){
		p2[i].fi=x-p[i].fi;
		p2[i].se=y-p[i].se;
	}
	sort(p2,p2+n);
	rep(i,0,n){
		if(p[i]!=p2[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}