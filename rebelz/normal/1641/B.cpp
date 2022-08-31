// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,m1;
int a[505],b[506],p[505],num[505];
vector<pii> ans;
vector<int> res;

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) p[i]=a[i]=readint();
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+n+1,a[i])-p;
		for(int i=1;i<=n;i++) num[i]=0;
		for(int i=1;i<=n;i++) num[a[i]]++;
		bool fl=0;
		for(int i=1;i<=n;i++) if(num[i]&1) fl=1;
		if(fl){
			printf("-1\n");
			continue;
		}
		int now=0;
		m=n;
		ans.clear(),res.clear();
		while(m){
			int pl=0;
			for(int j=2;j<=m;j++){
				if(a[1]==a[j]){
					pl=j;
					break;
				}
			}
			for(int j=2;j<pl;j++) ans.pb(mp(now+pl+j-2,p[a[j]]));
			res.pb(2*(pl-1));
			m1=0;
			for(int i=pl-1;i>=2;i--) b[++m1]=a[i];
			for(int i=pl+1;i<=m;i++) b[++m1]=a[i];
			for(int i=1;i<=m1;i++) a[i]=b[i];
			m=m1;
			now+=2*(pl-1);
		}
		printf("%d\n",ans.size());
		for(auto r:ans) printf("%d %d\n",r.fi,r.se);
		printf("%d\n",res.size());
		for(auto r:res) printf("%d ",r);
		printf("\n");
	}
	return 0;
}