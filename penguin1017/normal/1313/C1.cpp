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
int a[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]);
	int pos=0;
	ll ans=0;
	rep(i,0,n){
		int maxn=a[i];
		ll res=a[i];
		per(j,0,i){
			maxn=min(maxn,a[j]);
			res+=maxn;
		} 
		maxn=a[i];
		rep(j,i+1,n){
			maxn=min(maxn,a[j]);
			res+=maxn;
		}
		if(ans<res){
			ans=res;
			pos=i;
		}
	}
	per(i,0,pos)a[i]=min(a[i],a[i+1]);
	rep(i,pos+1,n)a[i]=min(a[i],a[i-1]);
	rep(i,0,n)printf("%d ",a[i]);
}