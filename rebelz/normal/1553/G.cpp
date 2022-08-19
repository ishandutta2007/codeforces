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

const int N=1000001;
int n,q,tot;
int prm[1000005],p0[1000005],a[150005],bel[1000005],f[150005];
bool fl[1000005];
vector<int> vec[1000005],comp[150005];
set<int> st[150005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return;
	f[fx]=fy;
}

void getprime(){
	fl[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i,p0[i]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1,p0[i*prm[j]]=prm[j];
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	n=readint(); q=readint();
	getprime();
	for(int i=1;i<=n;i++) a[i]=readint(),f[i]=i;
	for(int i=1;i<=n;i++){
		int x=a[i];
		while(x>1){
			int tmp=p0[x];
			while(x%tmp==0) x/=tmp;
			vec[tmp].pb(i);
		}
	}
	for(int i=1;i<=N;i++){
		if(!vec[i].size()) continue;
		int th=vec[i][0];
		for(auto r:vec[i]) merge(r,th);
	}
	for(int i=1;i<=N;i++) if(vec[i].size()) bel[i]=getf(vec[i][0]);
	for(int i=1;i<=n;i++) comp[getf(i)].pb(i);
	for(int i=1;i<=n;i++){
		set<int> ps;
		int x=a[i];
		while(x>1){
			int tmp=p0[x];
			while(x%tmp==0) x/=tmp;
			ps.insert(tmp);
		}
		x=a[i]+1;
		while(x>1){
			int tmp=p0[x];
			while(x%tmp==0) x/=tmp;
			ps.insert(tmp);
		}
		for(auto r:ps)
			for(auto s:ps)
				if(bel[r]&&bel[s]) st[bel[r]].insert(bel[s]);
	}
	int x,y;
	while(q--){
		x=readint(); y=readint();
		int fx=getf(x),fy=getf(y);
		if(fx==fy) printf("0\n");
		else if(st[fx].find(fy)!=st[fx].end()||st[fy].find(fx)!=st[fy].end()) printf("1\n");
		else printf("2\n");
	}
	return 0;
}