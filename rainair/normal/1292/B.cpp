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
#define int LL
const int MAXN = 1e5 + 5;
LL x[MAXN],y[MAXN];

inline unsigned LL dis(LL x0,LL y0,LL x1,LL y1){
	return std::llabs(x0-x1)+std::llabs(y0-y1);
}

signed main(){
	LL ax,ay,bx,by,xs,ys,t;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by,&xs,&ys,&t);
	int n = 0;
	while(233){
		x[n+1] = x[n]*ax+bx;
		y[n+1] = y[n]*ay+by;
		// if(dis(xs,ys,x[n+1],y[n+1]) > t) break;
		if(x[n+1] < 0 || y[n+1] < 0) break;
		if(x[n+1] > 2e16 || y[n+1] > 2e16) break;
		++n;
	}
	int ans = 0;
	FOR(i,0,n){
		unsigned LL now = dis(xs,ys,x[i],y[i]),bk = now;
		if(now > t) continue;
		int tt = 1;
		FOR(j,0,i-1){
			tt = 1;now = bk;
			if(dis(x[i],y[i],x[j],y[j])+now > t) continue;
			tt += i-j;now += dis(x[i],y[i],x[j],y[j]);
			LL lx = x[j],ly = y[j];
			FOR(k,i+1,n){
				if(now+dis(lx,ly,x[k],y[k]) > t) break;
				now += dis(lx,ly,x[k],y[k]);
				lx = x[k];ly = y[k];tt++;
			}
			ans = std::max(ans,tt);
		}
		tt = 1;now = bk;
		FOR(j,i+1,n){
			tt = 1;now = bk;
			if(dis(x[i],y[i],x[j],y[j])+now > t) continue;
			tt += j-i;now += dis(x[i],y[i],x[j],y[j]);
			LL lx = x[j],ly = y[j];
			ROF(k,i-1,0){
				if(now+dis(lx,ly,x[k],y[k]) > t) break;
				now += dis(lx,ly,x[k],y[k]);
				lx = x[k];ly = y[k];tt++;
			}
			now = bk;
			ans = std::max(ans,tt);
		}
		tt = 1;now = bk;LL lx = x[i],ly = y[i];
		ROF(k,i-1,0){
				if(now+dis(lx,ly,x[k],y[k]) > t) break;
				now += dis(lx,ly,x[k],y[k]);
				lx = x[k];ly = y[k];tt++;
			}
			ans = std::max(ans,tt);
		tt = 1;now = bk;lx = x[i];ly = y[i];
		FOR(k,i+1,n){
				if(now+dis(lx,ly,x[k],y[k]) > t) break;
				now += dis(lx,ly,x[k],y[k]);
				lx = x[k];ly = y[k];tt++;
			}
			ans = std::max(ans,tt);
	}
	printf("%lld\n",ans);
	return 0;
}