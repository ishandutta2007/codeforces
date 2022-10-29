#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
int a[N],b[N];
pii ans[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]),a[i]+=10000,b[i]=a[i];
	sort(b+1,b+1+n);
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(a[j]==b[i]){
				a[j]=i;
				break;
			}
		}
	}
	int cnt=0;
	int i=1;
	while(i<=n){
		int maxn=0,p=0;
		rep(j,i+1,n+1){
			if(a[i]>a[j]){
				if(a[j]>maxn){
					maxn=a[j],p=j;
				}
			}
		} 
		if(p){
			ans[cnt++]={i,p};
			swap(a[i],a[p]);
		}
		else ++i;
	}
	printf("%d\n",cnt);
	rep(i,0,cnt)printf("%d %d\n",ans[i].fi,ans[i].se);
//	rep(i,1,n+1)printf("%d ",a[i]);cout<<"A\n";
}