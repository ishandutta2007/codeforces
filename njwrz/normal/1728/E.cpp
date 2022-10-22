#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;y=0;
		RE a;
	}
	int t=exgcd(b,a%b,y,x);y-=(a/b)*x;
	RE t;
}
//ax+by=gcd(a,b)
int n,a[300005],s[300005];
int sum;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		int x,y;
		cin>>x>>y;
		sum+=x;
		a[i]=y-x;
	}
	sort(a+1,a+n+1);
	int it=n;
	for(int i=n;i>=1;i--){
		if(a[i]<0){
			it=n-i;break;
		}
	}
	for(int i=n;i>=1;i--)s[i]=s[i+1]+a[i];
	int q;
	cin>>q;
	FOR(_,1,q){
		int a,b;
		cin>>a>>b;
		int x,y;
		int t=exgcd(a,b,x,y);
		if(n%t!=0){
			cout<<-1<<'\n';continue;
		}
		int ans=-1;
		x*=n/t;y*=n/t;x*=a;y*=b;
		int delx=a*b/t,dely=a*b/t;
		if(y<it){
			t=(it-y+dely-1)/dely;
			y+=dely*t;x-=delx*t;
		}else {
			t=(y-it)/dely;
			y-=dely*t;x+=delx*t;
		}
//		cout<<x<<' '<<y<<'\n';
		if(y>=0&&x>=0&&x<=n&&y<=n)gmax(ans,sum+s[n-y+1]);
		y-=dely;x+=delx;
		if(y>=0&&x>=0&&x<=n&&y<=n)gmax(ans,sum+s[n-y+1]);
		cout<<ans<<'\n';
	}
	RE 0;
}