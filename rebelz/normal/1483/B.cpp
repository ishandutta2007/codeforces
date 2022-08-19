#include<bits/stdc++.h>

#define y1 dmytxdy
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

int n;
int a[100005],nxt[100005],lst[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		a[n+1]=a[1];
		for(int i=1;i<=n;i++) nxt[i]=i+1,lst[i]=i-1;
		nxt[n]=1,lst[1]=n;
		set<int> s;
		for(int i=1;i<=n;i++) if(__gcd(a[i],a[i+1])==1) s.insert(i);
		vector<int> ans(0);
		int now=1;
		while(s.size()){
			auto it=s.lower_bound(now);
			if(it==s.end()) it=s.lower_bound(1);
			ans.pb(nxt[*it]);
			int p=nxt[*it];
			s.erase(it);
			int nx=nxt[p],ls=lst[p];
			if(ls==p) break;
			nxt[ls]=nx,lst[nx]=ls;
			if(__gcd(a[p],a[nx])==1) s.erase(p);
			if(__gcd(a[ls],a[nx])==1) s.insert(ls);
			now=nx;
		}
		printf("%d ",ans.size());
		for(auto r:ans) printf("%d ",r);
		printf("\n");
	}
	return 0;
}