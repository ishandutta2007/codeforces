#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;

struct Node{
	int l,r;LL sm;
	double val;
	Node(int l=0,int r=0,LL sm=0) : l(l),r(r),sm(sm) {val = 1.0*sm/(r-l+1);}

	inline Node operator + (const Node &t) const {
		return Node(std::min(l,t.l),std::max(r,t.r),sm+t.sm);
	}

	inline bool operator < (const Node &t) const {
		return val < t.val;
	}
}st[MAXN];
int tp;
int n;
int a[MAXN];
double ans[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n){
		Node now = Node(i,i,a[i]);
		while(tp && (st[tp]+now)<st[tp]){
			now = st[tp]+now;tp--;
		}
		st[++tp] = now;
	}
	FOR(i,1,tp){
		FOR(j,st[i].l,st[i].r) printf("%.10f\n",st[i].val);
	}
	return 0;
}