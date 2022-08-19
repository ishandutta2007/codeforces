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
int f[100005],siz[100005],cnt[100005];
vector<int> adj[100005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return;
	f[fx]=fy;
	return;
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].push_back(y),adj[y].push_back(x);
	}
	set<int> s;
	for(int i=1;i<=n;i++) f[i]=i,siz[i]=1,s.insert(i);
	for(int i=1;i<=n;i++){
		for(auto v:adj[i]) cnt[getf(v)]++;
		vector<int> t;
		for(auto x:s){
			if(cnt[x]==siz[x]) continue;
			if(x==getf(i)) continue;
			f[x]=getf(i),siz[getf(i)]+=siz[x];
			t.push_back(x);
		}
		for(auto x:t) s.erase(x);
		for(auto v:adj[i]) cnt[getf(v)]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(getf(i)==i) cnt++;
	printf("%d\n",cnt-1);
	return 0;
}