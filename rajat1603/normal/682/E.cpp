#include "bits/stdc++.h"
using namespace std;
const double eps = 1e-8;
const double inf = 1e100;
struct point{
	double x;
	double y;
	point(double _x = 0 , double _y = 0){
		x = _x;
		y = _y;
	}
	point operator + (const point &o) const {
		return point(x + o.x , y + o.y);
	}
	point operator - (const point &o) const {
		return point(x - o.x , y - o.y);
	}
	point operator * (const double c) const {
		return point(x * c , y * c);
	}
	point operator / (const double c) const {
		return point(x / c , y / c);
	}
	bool operator < (const point &o) const {
		return make_pair(x , y) < make_pair(o.x , o.y);
	}
	bool operator == (const point &o) const {
		return (abs(x - o.x) < eps) && (abs(y - o.y) < eps);
	}
	void read(){
		int xx , yy;
		scanf("%d %d" , &xx , &yy);
		x = xx;
		y = yy;
	}
	void print(){
		cout << fixed << setprecision(9) << x << " " << y << "\n";
	}
};
double dot(point a , point b){
	return a.x * b.x + a.y * b.y;
}
double cross(point a , point b){
	return a.x * b.y - a.y * b.x;
}
double dist(point a , point b){
	return dot(a - b , a - b);
}
bool colinear(point a , point b , point c){
	return abs(cross(b - a , c - a)) < eps;
}
bool clockwise(point a , point b , point c){
	return cross(b - a , c - a) < eps;
}
bool anticlock(point a , point b , point c){
	return cross(b - a , c - a) >= eps;
}
/*
	Point can be used as a line y = mx + c , incase slope is inf , c stores the value of X , point.x = m , point.y = c
*/
point meet(point a , point b){
	if(abs(a.x) < abs(b.x)){
		swap(a , b);
	}
	point ret;
	if(abs(a.x) > 1e50){
		ret.x = a.y;
	}
	else{
		ret.x = (b.y - a.y) / (a.x - b.x);
	}
	ret.y = b.x * ret.x + b.y;
	return ret;
}

double getc(double slope , point a){
	if(slope > 1e50){
		return a.x;
	}
	return a.y - slope * a.x;
}
point move(point base , double angle , double len){
	return point(base.x + cos(angle) * len , base.y + sin(angle) * len);
}
point rotatecw(point a , double angle){
	return point(a.x * cos(angle) + a.y * sin(angle) , a.y * cos(angle) - a.x * sin(angle));
}
point bottom;
bool cmp(point a , point b){
	double x = cross(a - bottom , b - bottom);
	if(abs(x) < eps){
		return dist(bottom , a) < dist(bottom , b);
	}
	return x < 0;
}
double area(const point &a , const point &b , const point &c){
	return abs(cross(b - a , c - a)) / 2.0;
}
double slope(const point &a , const point &b){
	if(abs(a.x - b.x) < eps){
		return inf;
	}
	return (b.y - a.y) / (b.x - a.x);
}
vector < point > convexhull(vector < point > &v){
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	v.shrink_to_fit();
	if(v.size() <= 2){
		return v;
	}
	int idx = 0;
	for(int i = 1 ; i < v.size() ; ++i){
		if(v[i].y < v[idx].y){
			idx = i;
		}
	}
	swap(v[idx] , v[0]);
	bottom = v[0];
	sort(v.begin() + 1 , v.end() , cmp);
	vector < point > hull;
	hull.clear();
	for(int i = 0 ; i < v.size() ; ++i){
		while(hull.size() >= 2 && cross(hull[hull.size() - 1] - hull[hull.size() - 2] , v[i] - hull[hull.size() - 1]) >= 0){
			hull.pop_back();
		}
		hull.emplace_back(v[i]);
	}
	return hull;
}
bool inside(vector < point > &polygon , const point &p){//convex polygon sorted in clockwise order
	int n = polygon.size();
	for(int i = 0 ; i < n ; ++i){
		if(anticlock(polygon[i] , polygon[(i + 1) % n] , p)){
			return 0;
		}
	}
	return 1;
}
int n;
long long s;
vector < point > arr;
void solve(){
	int a = 0 , b = 1 , c = 2;
	int k = 2;
	n = arr.size();
	for(int i = 0 ; i < n ; ++i){
		k = (i + 2) % n;
		for(int j = (i + 1) % n ; j != i ; j = (j + 1) % n){
			while(area(arr[i] , arr[j] , arr[(k + 1) % n]) > area(arr[i] , arr[j] , arr[k])){
				k = (k + 1) % n;
			}
			if(area(arr[i] , arr[j] , arr[k]) > area(arr[a] , arr[b] , arr[c])){
				a = i;
				b = j;
				c = k;
			}
		}
	}
	point p1 , p2 , p3;
	p1.x = slope(arr[a] , arr[b]);
	p2.x = slope(arr[b] , arr[c]);
	p3.x = slope(arr[c] , arr[a]);
	p1.y = getc(p1.x , arr[c]);
	p2.y = getc(p2.x , arr[a]);
	p3.y = getc(p3.x , arr[b]);
	point ans1 = meet(p1 , p2);
	point ans2 = meet(p2 , p3);
	point ans3 = meet(p3 , p1);
	printf("%lld %lld\n" , (long long)round(ans1.x) , (long long)round(ans1.y));
	printf("%lld %lld\n" , (long long)round(ans2.x) , (long long)round(ans2.y));
	printf("%lld %lld\n" , (long long)round(ans3.x) , (long long)round(ans3.y));
}
int main(){
	scanf("%d %lld" , &n , &s);
	arr.resize(n);
	arr.shrink_to_fit();
	for(int i = 1 ; i <= n ; ++i){
		arr[i - 1].read();
	}
	arr = convexhull(arr);
	solve();
}