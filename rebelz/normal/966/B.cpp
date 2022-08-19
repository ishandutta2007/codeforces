#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,x1,x2;
int now[2];
pii a[300005],b[600005];

int main(){
	n=readint(); x1=readint(); x2=readint();
	for(int i=1;i<=n;i++) a[i]=mp(readint(),i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=mp((x1+i-1)/i,i);
	for(int i=1;i<=n;i++) b[n+i]=mp((x2+i-1)/i,-i);
	sort(b+1,b+n+n+1);
	now[0]=now[1]=n+1;
	int ans0=0,ans1=0;
	for(int i=n+n;i>=1;i--){
		int pl=lower_bound(a+1,a+n+1,mp(b[i].fi,0))-a;
		if(n-pl+1>=abs(b[i].se)){
			if(b[i].se>0) chkmin(now[0],b[i].se);
			else chkmin(now[1],-b[i].se);
		}
		if(b[i].se>0){
			if(n-pl+1>=b[i].se+now[1]){
				ans0=b[i].se,ans1=now[1];
				break;
			}
		}
		else{
			if(n-pl+1>=-b[i].se+now[0]){
				ans0=now[0],ans1=-b[i].se;
				break;
			}
		}
	}
	if(!ans0) printf("No\n");
	else{
		vector<int> v0(0),v1(0);
		if((x1+ans0-1)/ans0>(x2+ans1-1)/ans1){
			for(int i=n;i>=n-ans0+1;i--) v0.pb(a[i].se);
			for(int i=n-ans0;i>=n-ans0-ans1+1;i--) v1.pb(a[i].se);
		}
		else{
			for(int i=n;i>=n-ans1+1;i--) v1.pb(a[i].se);
			for(int i=n-ans1;i>=n-ans1-ans0+1;i--) v0.pb(a[i].se);
		}
		sort(v0.begin(),v0.end());
		sort(v1.begin(),v1.end());
		printf("Yes\n");
		printf("%d %d\n",v0.size(),v1.size());
		for(auto r:v0) printf("%d ",r);
		printf("\n");
		for(auto r:v1) printf("%d ",r);
		printf("\n");
	}
	return 0;
}