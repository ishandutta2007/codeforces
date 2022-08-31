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
int a[20],b[20],c[500005],ans[500005];
vector<pii> qry[500005];

void insert(int x,int id){
	for(int i=19;i>=0;i--){
		if(x&(1<<i)){
			if(a[i]){
				if(id>b[i]) swap(b[i],id),swap(x,a[i]);
				x^=a[i];
			}
			else{
				a[i]=x,b[i]=id;
				return;
			}
		}
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) c[i]=readint();
	m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		qry[y].pb(mp(x,i));
	}
	for(int i=1;i<=n;i++){
		insert(c[i],i);
		for(auto r:qry[i])
			for(int j=19;j>=0;j--)
				if(!((ans[r.se]>>j)&1)&&a[j]&&b[j]>=r.fi)
					ans[r.se]^=a[j];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}