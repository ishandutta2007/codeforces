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
int n;LL S;

struct Node{
	LL x,y;
	Node(LL x=0,LL y=0) : x(x),y(y) {}
	
	inline Node operator - (const Node &t) const {
		return Node(x-t.x,y-t.y);
	}
	
	inline LL operator * (const Node &t) const {
		return x*t.y-y*t.x;
	}
}a[MAXN];
std::vector<std::pair<Node,P> > b;

inline bool cmp1(const Node &a,const Node &b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}

inline bool cmp2(const std::pair<Node,P> &a,const std::pair<Node,P> &b){
	return a.fi*b.fi > 0;
}

int rk[MAXN],p[MAXN];

int main(){
	scanf("%d%lld",&n,&S);S <<= 1;
	FOR(i,1,n) scanf("%lld%lld",&a[i].x,&a[i].y),rk[i] = p[i] = i;
	std::sort(a+1,a+n+1,cmp1);
	FOR(i,1,n) FOR(j,i+1,n) b.pb(MP(a[j]-a[i],MP(i,j)));
	std::sort(all(b),cmp2);//DEBUG(S);
	for(auto x:b){
		int i = x.se.fi,j = x.se.se;
		int l = 1,r = rk[i]-1;
		while(l <= r){
			int mid = (l + r) >> 1;
			LL area = std::llabs((a[j]-a[i])*(a[p[mid]]-a[i]));
			if(area == S){
				printf("Yes\n%lld %lld\n%lld %lld\n%lld %lld\n",a[i].x,a[i].y,a[j].x,a[j].y,a[p[mid]].x,a[p[mid]].y);
				return 0;
			}
			if(area < S) r = mid-1;
			else l = mid+1;
		}
		l = rk[i]+1,r = n;
		bool flag = 0;
		// FOR(ii,rk[i]+1,n){
			// if(std::abs((a[j]-a[i])*(a[p[ii]]-a[i])) == 7020){
				// flag = 1;
			// }
		// }
		while(l <= r){
			int mid = (l + r) >> 1;
			LL area = std::llabs((a[j]-a[i])*(a[p[mid]]-a[i]));
			// if(flag) DEBUG(l),DEBUG(r),DEBUG(area);
			if(area == S){
				printf("Yes\n%lld %lld\n%lld %lld\n%lld %lld\n",a[i].x,a[i].y,a[j].x,a[j].y,a[p[mid]].x,a[p[mid]].y);
				return 0;
			}
			if(area < S) l = mid+1;
			else r = mid-1;
		}
		// if(flag) exit(0);
		std::swap(p[rk[i]],p[rk[j]]);
		std::swap(rk[i],rk[j]);
	}
	puts("No");
	return 0;
}