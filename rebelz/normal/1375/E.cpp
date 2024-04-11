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

int n;
int a[1005];
pii p[1005];
vector<int> inv[1005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),p[i]=mp(a[i],i);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+n+1,mp(a[i],i))-p;
	int siz=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]<a[i]) siz++;
	printf("%d\n",siz);
	for(int i=1;i<=n;i++){
		int now=1<<30,opt=0;
		for(int j=i+1;j<=n;j++) if(a[j]<a[i]) inv[i].pb(j);
		sort(inv[i].begin(),inv[i].end(),[&](int x,int y){return a[x]>a[y];});
		for(auto r:inv[i]) printf("%d %d\n",i,r),swap(a[i],a[r]);
	}
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//	cout<<endl;
	return 0;
}