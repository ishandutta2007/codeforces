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
const int N=2e6+9;
const ll mod=998244353;
int a[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]);
	sort(a,a+n);
	int ans=0;
	rep(i,0,n)if(a[i]!=a[0]&&a[i]!=a[n-1])++ans;
	printf("%d",ans);
}