#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	long long x;
	long long y;
};

vector<Point> point;
long long x0,y0,ax,ay,bx,by;
long long xs,ys,t;

long long julde(long long x) {
	if (x<0)
	return -x;
	return x;
}

int cal(int k) {
	long long tleft=t-julde(point[k].x-xs)-julde(point[k].y-ys);
	if (tleft<0) {
		return 0;
	}
	vector<long long> dist;
	for(int i=0;i<point.size();i++) {
		dist.push_back(julde(point[k].x-point[i].x)+julde(point[k].y-point[i].y));
	}
	int ret=1;
	for(int i=0;i<k;i++) {
		long long templeft=tleft-dist[i];
		if (templeft<0) {
			continue;
		}
		templeft-=dist[i];
		int reach=0;
		for(int i=k+1;i<point.size();i++) {
			if (dist[i]<=templeft) {
				reach++;
			}
		}
		ret=max(ret,k-i+1+reach);
	}
	for(int i=k+1;i<point.size();i++) {
		long long templeft=tleft-dist[i];
		if (templeft<0) {
			continue;
		}
		templeft-=dist[i];
		int reach=0;
		for(int i=k-1;i>=0;i--) {
			if (dist[i]<=templeft) {
				reach++;
			}
		}
		ret=max(i-k+1+reach,ret);
	}
	return ret;
}

int main(void) {
	scanf("%lld %lld %lld %lld %lld %lld\n",&x0,&y0,&ax,&ay,&bx,&by);
	scanf("%lld %lld %lld",&xs,&ys,&t);
	long long x=x0;
	long long y=y0;
	while(x<=3e16&&y<=3e16) {
		point.push_back({x,y});
		x=ax*x+bx;
		y=ay*y+by;
	}
	int ret=0;
	for(int i=0;i<point.size();i++) {
		ret=max(ret,cal(i));
	}
	printf("%d",ret);
}