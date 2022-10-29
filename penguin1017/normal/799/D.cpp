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
ll maxn=1e15,sum=1;
int a,b,h,w,n;
int p[N],cnt,p2[N],flag,x[4];
ll mul[N],mul2[N];
int main(){
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	rep(i,0,n)scanf("%d",&p[i]);
	if(h>=a&&w>=b){
		cout<<0;
		return 0;
	}
	if(h>=b&&w>=a){
		cout<<0;
		return 0;
	}
	x[0]=a/h+(a%h?1:0);
	x[1]=b/w+(b%w?1:0);
	x[2]=a/w+(a%w?1:0);
	x[3]=b/h+(b%h?1:0);
	mul[0]=1;mul2[0]=1;
	int last=1,cnt=1,pri=0;
	ll tot=1;
sort(p,p+n);
	per(i,0,n){
		if(tot>maxn/p[i]){
			printf("%d",n-i);
			return 0;
		}
		tot*=p[i];
		if(p[i]==pri){
			rep(j,0,last){
				mul[j+cnt]=mul[j+cnt-last]*p[i];
			}
			cnt+=last;
		}
		else{
			pri=p[i];
			last=cnt;
			rep(j,0,last)mul[j+cnt]=mul[j]*p[i];
			cnt+=last;
		}
		rep(j,0,cnt){
			mul2[j]=tot/mul[j];
			if(mul[j]>=x[0]&&mul2[j]>=x[1]){
				printf("%d",n-i);
				return 0;
			}
			if(mul[j]>=x[2]&&mul2[j]>=x[3]){
				printf("%d",n-i);
				return 0;
			}
		}
	}
	printf("-1");
}