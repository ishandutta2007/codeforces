#pragma GCC optimize("Ofast")
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int s[100005],a[100005],sum1,sum2,n,fr,se;
void up(int x,int p){
	while(x<=n){
		s[x]+=p;
		x+=x&-x;
	}
}
int get(int x){
	int re=0;
	while(x){
		re+=s[x];
		x-=x&-x;
	}
	RE re;
}
bool check(int x){
	RE (x-sum2>=se-x&&x-sum1>=fr-x);
}
void solve(){
	int l=-1e18,r=1e18,ans,mid;fr=get(1);se=get(n);
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;r=mid-1;
		}else l=mid+1;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin>>n;
	FOR(i,1,n){
		cin>>x;a[i]=x;
		up(i+1,-x);
		up(i,x);
	}
	FOR(i,2,n){
		if(a[i]>a[i-1]){
			sum1+=a[i]-a[i-1];
		}else sum2+=a[i-1]-a[i];
	}
	solve();
	int q,l,r;
	cin>>q;
	FOR(i,1,q){
		cin>>l>>r>>x;
		if(l!=1){
			int t1,t2;
			t1=get(l-1);t2=get(l);
			if(t1>t2){
				sum2-=t1-t2;
			}else sum1-=t2-t1;
			t2+=x;
			if(t1>t2){
				sum2+=t1-t2;
			}else sum1+=t2-t1;
		}
//		cout<<sum1<<' '<<sum2<<'\n';
		if(r!=n){
			int t1,t2;
			t1=get(r);t2=get(r+1);
			if(t1>t2){
				sum2-=t1-t2;
			}else sum1-=t2-t1;
			t1+=x;
			if(t1>t2){
				sum2+=t1-t2;
			}else sum1+=t2-t1;
		}
//		cout<<sum1<<' '<<sum2<<'\n';
		up(l,x);
		up(r+1,-x);
		solve();
	}
	RE 0;
}