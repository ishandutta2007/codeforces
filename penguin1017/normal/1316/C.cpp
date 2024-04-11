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
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int a[N],b[N],posa[N],posb[N],cnt,cnt2;
int main(){
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	rep(i,0,n){
		scanf("%d",&a[i]);
		if(a[i]%p)posa[cnt++]=i;
	}
	rep(i,0,m){
		scanf("%d",&b[i]);
		if(b[i]%p)posb[cnt2++]=i;
	}
	while(1){
		ll ans=0;
		int r=(rand()<<15)+rand(),x;
		x=posa[r%cnt];
		r=(rand()<<15)+rand();
		x+=posb[r%cnt];
		rep(i,max(0,x-m+1),min(x+1,n)){
			if(i>=n)break;
			ans=(ans+1ll*a[i]*b[x-i])%p;
		}
		if(ans){
			printf("%d",x);
			return 0;
		}
	}
}