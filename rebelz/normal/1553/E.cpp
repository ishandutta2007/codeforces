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

int n,m;
int a[300005],b[300005],p[300005],q[300005],f[300005],cnt[300005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return;
	f[fx]=fy;
}

bool check(int x){
	for(int i=1;i<=n;i++) b[i]=(i-x+n-1)%n+1;
	for(int i=1;i<=n;i++) q[b[i]]=i;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++) merge(p[i],q[i]);
	int num=0;
	for(int i=1;i<=n;i++) if(getf(i)==i) num++;
	if(n-num<=m) return true;
	else return false;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			int tmp=i-a[i];
			if(tmp<0) tmp+=n;
			cnt[tmp]++;
		}
		vector<int> ans(0);
		for(int i=0;i<n;i++) if(cnt[i]>=n-2*m&&check(i)) ans.pb(i);
		printf("%d ",ans.size());
		for(auto r:ans) printf("%d ",r);
		printf("\n");
	}
	return 0;
}