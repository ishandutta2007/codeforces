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

const int B=50;
int n,m,k;
int w[100005],a[100005][5],w1[100005],a1[100005][5],p[500005],per[100005],num[500005],rnk[500005],dfn[500005];
bitset<100005> b[10005];
vector<int> vec[500005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) p[(i-1)*m+j]=a[i][j]=readint();
		w[i]=readint();
	}
	for(int i=1;i<=n;i++) per[i]=i;
	sort(per+1,per+n+1,[&](int x,int y){return w[x]<w[y];});
	for(int i=1;i<=n;i++){
		w1[i]=w[per[i]];
		for(int j=1;j<=m;j++) a1[i][j]=a[per[i]][j];
	}
	for(int i=1;i<=n;i++){
		w[i]=w1[i];
		for(int j=1;j<=m;j++) a[i][j]=a1[i][j];
	}
	sort(p+1,p+n*m+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=lower_bound(p+1,p+n*m+1,a[i][j])-p;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) num[a[i][j]]++;
	for(int i=1;i<=n*m;i++) if(num[i]>B) rnk[i]=++k,dfn[k]=i;
	for(int i=1;i<=k;i++) b[i].flip();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(num[a[i][j]]>B) b[rnk[a[i][j]]][i]=0;
			else vec[a[i][j]].pb(i);
		}
	}
	int ans=2000000001;
	for(int i=1;i<n;i++){
		if(w[i]+w[i+1]>=ans) break;
		bool fl=0;
		bitset<100005> now;
		for(int j=1;j<=m;j++){
			if(num[a[i][j]]>B){
				if(!fl) now=b[rnk[a[i][j]]],fl=1;
				else now&=b[rnk[a[i][j]]];
			}
		}
		if(!fl){
			for(int j=1;j<=B*m+1;j++) now[j]=1;
		}
		now[100004]=1,now[0]=0;
		for(int j=1;j<=m;j++){
			if(num[a[i][j]]<=B){
				for(auto r:vec[a[i][j]]) now[r]=0;
			}
		}
		int pl=now._Find_first();
		if(pl<=n) chkmin(ans,w[i]+w[pl]);
	}
	printf("%d\n",ans>2000000000?-1:ans);
	return 0;
}