#include <stdio.h>
#include <bits/stdc++.h>
#define int long long

using namespace std;

void G() {
	printf("NO\n") , exit(0);
}

const int N = 2e5 + 10 , inf = 4e18;
int n , l , xl = -inf , xr = inf , yl = -inf , yr = inf;

struct Node {
	int t , x , y , k , w;
	void I() {
		int t1 , t2;
		scanf("%lld%lld%lld" , &t , &t1 , &t2);
		if((t1 ^ t2 ^ t) & 1) G();
		k = t / l , w = t % l;
		x = (t1 + t2 + t) / 2 , y = (t1 - t2 + t) / 2;
	}
	bool operator < (const Node A)const {return w < A.w;}
}	o[N];

signed main() {
	scanf("%lld%lld" , &n , &l);
	for(int i = 1; i <= n; i++) o[i].I();
	sort(o + 1 , o + n + 1);
	o[++n].k = -1 , o[n].w = l;
	
	for(int i = 1; i <= n; i++) {
		Node A = o[i - 1] , B = o[i];
		int k = B.k - A.k , w = B.w - A.w , x = B.x - A.x , y = B.y - A.y;
		if(k == 0) {
			if(!(0 <= x && x <= w))	G();
			if(!(0 <= y && y <= w)) G();
		}
		else if(k > 0) {
			xl = max(xl , (int)ceil((long double)(x - w) * 1.0l / k)) , xr = min(xr , (int)floor((long double)x * 1.0l / k));
			yl = max(yl , (int)ceil((long double)(y - w) * 1.0l / k)) , yr = min(yr , (int)floor((long double)y * 1.0l / k));
		}
		else if(k < 0) {
			xl = max(xl , (int)ceil((long double)x * 1.0l / k)) , xr = min(xr , (int)floor((long double)(x - w) * 1.0l / k));
			yl = max(yl , (int)ceil((long double)y * 1.0l / k)) , yr = min(yr , (int)floor((long double)(y - w) * 1.0l / k));
		}
	}
	if(xl > xr || yl > yr) G();
	for(int i = 1; i <= n; i++)
	{
		int tx = (o[i].x - xl * o[i].k) - (o[i - 1].x - xl * o[i - 1].k);
		int ty = (o[i].y - yl * o[i].k) - (o[i - 1].y - yl * o[i - 1].k);
		int T = o[i].w - o[i - 1].w , x = 0 , y = 0;
		while(T--) {
			if(x == tx && y == ty) {
				printf("L");
				while(T--) printf("L");
				break;
			}
			if(x < tx) {
				if(y < ty) printf("R") , x++ , y++;
				else printf("U") , x++;
			}
			else {
				if(y < ty) printf("D") , y++;
				else printf("L");
			}
		}
	}
	printf("\n");
	return 0;
}