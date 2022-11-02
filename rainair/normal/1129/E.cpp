#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 500 + 5;
int sz[MAXN],n;

inline int query(std::vector<int> v1,std::vector<int> v2,int v){ // v1->v->v2
	printf("%d\n",(int)v1.size());
	for(auto x:v1) printf("%d ",x);puts("");
	printf("%d\n",(int)v2.size());
	for(auto x:v2) printf("%d ",x);puts("");
	printf("%d\n",v);std::fflush(stdout);int res;scanf("%d",&res);return res;
}

int id[MAXN];

inline bool cmp(int x,int y){
	return sz[x] < sz[y];
}

std::vector<int> S;
std::vector<P> ans;

inline int find(int x){
	if(S.empty()) return -1;
	int l = 0,r = (int)S.size()-1,ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;std::vector<int> v;
		FOR(i,0,mid) v.pb(S[i]);
		if(query({1},v,x)) ans = mid,r = mid-1;
		else l = mid+1;
	}
	if(ans != -1){
		int res = S[ans];
		S.erase(S.begin()+ans);
		return res;
	}
	return -1;
}

int main(){
	scanf("%d",&n);sz[1] = n;
	std::vector<int> v;FOR(i,2,n) v.pb(i);
	FOR(i,2,n) sz[i] = query({1},v,i);
//	sz[2] = 4;sz[3] = 2;sz[4] = sz[5] = 1;
	std::iota(id+1,id+n+1,1);
	std::sort(id+1,id+n+1,cmp);assert(id[n]==1);
	FOR(i,1,n-1){
		int t = -1;
		while((t=find(id[i])) != -1) ans.pb(MP(id[i],t));
		S.pb(id[i]);
	}
	for(auto x:S) ans.pb(MP(1,x));
	puts("ANSWER");
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);puts("");
	std::fflush(stdout);
	return 0;
}