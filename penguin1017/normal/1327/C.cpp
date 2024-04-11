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
	int n,m,k,x,y;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,k)scanf("%d%d",&x,&y);
	printf("%d\n",n+m+n*m-1);
	rep(i,0,n)printf("U");
	rep(i,0,m)printf("L");
	rep(i,0,n){
		if(i&1){
			rep(i,1,m)printf("L");
		}
		else{
			rep(i,1,m)printf("R");
		}
		if(i!=n-1)printf("D");
	}
}