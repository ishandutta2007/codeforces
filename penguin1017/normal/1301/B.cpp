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
int a[N];
const ll mod=998244353;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		//cout<<t<<"T\n";
		int n;
		scanf("%d",&n);
		rep(i,0,n){
			scanf("%d",&a[i]);
		}
		int d=0,ans=0,mini=1e9+10,maxn=0;
		rep(i,0,n){
			if(a[i]==-1){
				if(i){
					if(a[i-1]!=-1){
						mini=min(mini,a[i-1]);
						maxn=max(maxn,a[i-1]);
					}
				}
				if(i+1<n){
					if(a[i+1]!=-1){
						mini=min(mini,a[i+1]);
						maxn=max(maxn,a[i+1]);
					}
				}
			}
		}
		if(maxn>mini)d=(maxn-mini)>>1;
	//	cout<<maxn<<' '<<mini<<' '<<d<<"d\n";
		int num=maxn-d;
		rep(i,0,n){
			if(a[i]==-1)a[i]=num;
		}
		rep(i,1,n)ans=max(ans,abs(a[i]-a[i-1]));
		printf("%d %d\n",ans,num);
	}
}
/*
7 
5
-1 10 -1 12 -1
5
-1 40 35 -1 35
6
-1 -1 9 -1 3 -1
2
- 1 -1
2
0 -1
4
1 -1 3 -1
7
1 -1 7 5 2 -1 5
*/