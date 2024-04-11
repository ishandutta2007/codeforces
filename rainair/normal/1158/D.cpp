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

const int MAXN = 2000+5;
int n;

struct Node{
	LL x,y;int id;
	Node(LL x=0,LL y=0,int id=0) : x(x),y(y),id(id) {}
	
	inline bool operator < (const Node &t) const {
		return x < t.x;
	}
	
	inline Node operator - (const Node &t) const {
		return Node(x-t.x,y-t.y);
	}

	inline LL operator * (const Node &t) const {
		return x*t.y-y*t.x;
	}
}a[MAXN];
int b[MAXN];
bool del[MAXN];

inline int find(int x,int o){ // 0 = left 1 = right
	int res = -1;
	FOR(i,1,n){
		if(i == x || del[i]) continue;
		if(res == -1) res = i;
		else if(((a[res]-a[x])*(a[i]-a[x]) > 0)^o) res = i;
	}
	return res;
}

char str[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld%lld",&a[i].x,&a[i].y),a[i].id = i;
	std::sort(a+1,a+n+1);int las = 1;
	b[1] = a[1].id;del[1] = 1;
	scanf("%s",str+1);
	FOR(i,1,n-2){
		int t = find(las,str[i]=='L');
		b[i+1] = a[t].id;las = t;del[las] = 1;
	}
	FOR(i,1,n) if(!del[i]) b[n] = a[i].id;
	FOR(i,1,n) printf("%d ",b[i]);puts("");
	return 0;
}