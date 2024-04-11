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
ll a[N];
int cnt[100];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		memset(cnt,0,sizeof cnt);
		rep(i,0,n){
			scanf("%lld",&a[i]);
			int pos=0;
			while(a[i]){
				cnt[pos++]+=a[i]%k;
				a[i]/=k;
			}
		}
		int flag=0;
		rep(i,0,100)if(cnt[i]>1)flag=1;
		if(flag)printf("NO\n");
		else printf("YES\n");
	}
}