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

const int MAXN = 50+5;

struct Node{
	int x,y,id;
}a[MAXN],b[MAXN];
int n,m;
std::vector<std::pair<P,P> > S[3];

inline bool cmp1(const Node &a,const Node &b){
	return a.x < b.x;
}

inline bool cmp2(const Node &a,const Node &b){
	return a.id < b.id;
}

inline void work(Node a[],int o){
	FOR(i,1,m) while(a[i].x > i) S[o].pb(MP(MP(a[i].x,a[i].y),MP(a[i].x-1,a[i].y))),a[i].x--;
	ROF(i,m,1) while(a[i].x < i) S[o].pb(MP(MP(a[i].x,a[i].y),MP(a[i].x+1,a[i].y))),a[i].x++;
	FOR(i,1,m) while(a[i].y > a[i].id) S[o].pb(MP(MP(a[i].x,a[i].y),MP(a[i].x,a[i].y-1))),a[i].y--;
	ROF(i,m,1) while(a[i].y < a[i].id) S[o].pb(MP(MP(a[i].x,a[i].y),MP(a[i].x,a[i].y+1))),a[i].y++;
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id = i;
	}
	FOR(i,1,m){
		scanf("%d%d",&b[i].x,&b[i].y);
		b[i].id = i;
	}
	std::sort(a+1,a+m+1,cmp1);std::sort(b+1,b+m+1,cmp1);
	work(a,0);work(b,2);
	std::sort(a+1,a+m+1,cmp2);std::sort(b+1,b+m+1,cmp2);
	FOR(i,1,m){
		while(a[i].x < b[i].x) S[1].pb(MP(MP(a[i].x,a[i].y),MP(a[i].x+1,a[i].y))),a[i].x++;
		while(a[i].x > b[i].x) S[1].pb(MP(MP(a[i].x,a[i].y),MP(a[i].x-1,a[i].y))),a[i].x--;
	}
	printf("%d\n",(int)S[0].size()+S[1].size()+S[2].size());
	for(auto &x:S[2]) std::swap(x.fi,x.se);
	std::reverse(all(S[2]));
	FOR(i,0,2) for(auto x:S[i]) printf("%d %d %d %d\n",x.fi.fi,x.fi.se,x.se.fi,x.se.se);
	return 0;
}