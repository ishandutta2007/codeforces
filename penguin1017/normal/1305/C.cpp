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
const int N=1e3+9;
const ll mod=998244353;
int a[N],x[200009];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n){
		scanf("%d",&x[i]);
		a[x[i]%m]++;
	}
	int ans=1;
	rep(i,0,m){
		if(a[i]>1){
			printf("0");
			return 0;
		}
	}
	rep(i,0,n){
		rep(j,i+1,n){
			ans=(1ll*ans*abs(x[i]-x[j]))%m;
		}
	}
	printf("%d",ans);
}