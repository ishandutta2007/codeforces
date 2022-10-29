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
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c,d,u,v,xl,xr,yl,yr;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		scanf("%d%d%d%d%d%d",&u,&v,&xl,&yl,&xr,&yr);
		int x=u-a+b;
		int y=v-c+d;
		if(x<xl||x>xr||y<yl||y>yr){
			printf("No\n");
			continue;
		}
		if(xl==xr&&(a||b)){
			printf("No\n");
			continue;
		}
		if(yl==yr&&(c||d)){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
}