#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
long long xo , yo;
long long v , t;
int n;
struct point{
	double x;
	double y;
	point(double _x = 0 , double _y = 0){
		x = _x;
		y = _y;
	}
};
long long x[N];
long long y[N];
long long r[N];
vector < pair < double , double > > ans;
double sqr(double x){
	return x * x;
}
double dist(point a , point b){
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}
point move(point start , double angle , double dist){
	return point(start.x + cos(angle) * dist , start.y + sin(angle) * dist);
}
point o;
const double pi = acos(-1.0);
double subtend(point p1 , point p2){
	return atan2(p2.y - p1.y , p2.x - p1.x);
}
long long sqrll(long long x){
	return x * x;
}
void solve(int idx){
	point p = point(x[idx] , y[idx]);
	if(sqrt(dist(p , o)) - r[idx] > v * t){
		return;
	}
	if(sqrll(x[idx]) + sqrll(y[idx]) <= sqrll(r[idx])){
		printf("1.00000000\n");
		exit(0);
	}
	double angle = 0.0;
	double angel = subtend(p , o);
	double mx = acos(r[idx] / sqrt(dist(o , p)));
	if(sqrt(dist(p , o) + sqr(r[idx])) <= v * t){
		angle = mx;
	}
	else{
		double l = 0.0;
		double r = mx;
		for(int i = 0 ; i < 60 ; ++i){
			double mid = (l + r) / 2.0;
			point tmp = move(p , angel + mid , ::r[idx]);
			if(dist(tmp , o) <= sqr(v * t)){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		angle = (l + r) / 2.0;
	}
	angle = max(angle , 1e-9);
	point tmp1 = move(p , angel - angle , r[idx]);
	point tmp2 = move(p , angel + angle , r[idx]);
	ans.emplace_back(make_pair(subtend(o , tmp2) , subtend(o , tmp1)));
}
int main(){
	scanf("%lld %lld %lld %lld" , &xo , &yo , &v , &t);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lld %lld %lld" , x + i , y + i , r + i);
		x[i] -= xo;
		y[i] -= yo;
	}
	ans.clear();
	for(int i = 1 ; i <= n ; ++i){
		solve(i);
	}
	for(auto &it : ans){
		if(it.first < 0){
			it.first = 2 * pi + it.first;
		}
		if(it.second < 0){
			it.second = 2.0 * pi + it.second;
		}
	}
	vector < pair < double , double > > v2;
	v2.clear();
	for(auto &it : ans){
		if(it.first > it.second){
			double tmp = it.second;
			it.second = 2 * pi;
			v2.emplace_back(make_pair(0.0 , tmp));
		}
	}
	for(auto it : v2){
		ans.emplace_back(it);
	}
	double print = 0.0;
	vector < pair < double , int > > v;
	v.clear();
	for(auto it : ans){
		v.emplace_back(it.first , 1);
		v.emplace_back(it.second , -1);
	}
	int tot = 0;
	double lst;
	sort(v.begin() , v.end());
	for(auto it : v){
		if(it.second == 1){
			++tot;
			if(tot == 1){
				lst = it.first;
			}
		}
		else{
			--tot;
			if(!tot){
				print += it.first - lst;
			}
		}
		//assert(tot >= 0);
	}
	printf("%.9lf\n" , print / (2.0 * pi));
}