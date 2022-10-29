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
int a[N],b[N];
int main(){
	int n;
	int ans=0;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]);
	for(int op=1;op<2e7;op<<=1){
		rep(i,0,n)b[i]=a[i]&(op-1);
		int sum=0;
		rep(i,0,n)sum+=(a[i]&op)!=0;
		if((sum&1)&&((n-1)&1))ans^=op;
		sum=0;
		sort(b,b+n);
		int p=n-1;
		rep(i,0,n){
			p=max(i,p);
			for(;p>i&&b[p]+b[i]>=op;--p);
			sum^=(n-1-p);
		}
		if(sum&1)ans^=op;
	}
	cout<<ans;
}