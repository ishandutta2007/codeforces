#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define Point pair <long long, long long> 

bool cross (const Point p1, const Point p2, const Point p3) {
    return (p2.y - p1.y) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.y - p1.y) > 0;
}

vector <Point> convex_hull (vector <Point> p) {
    vector <Point> ret;
    sort (p.begin(), p.end());
	p.resize (unique (p.begin(), p.end()) - p.begin());

    for (int i = 0; i < p.size(); i++) {
        while (ret.size() >= 2 && cross (ret[ret.size() - 2], ret[ret.size() - 1], p[i])) 
            ret.pop_back();
        
        ret.push_back(p[i]);
    }
	
    int lower_hull_size = ret.size();

    for (int i = p.size() - 2; i >= 0; i--) {
        while (ret.size() - lower_hull_size >= 2 && cross(ret[ret.size() - 2], ret[ret.size() - 1], p[i])) {
            ret.pop_back();
        }
        ret.push_back(p[i]);
    }
    return ret;
}

long long Area (Point p1, Point p2, Point p3) { 
	return abs (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x); 
}

int main () {
    int n;
	long long S;
	vector <Point> p;
	scanf ("%d %lld", &n, &S);
	for (int i = 0; i < n; i++) {
		long long x, y;
		scanf ("%lld %lld", &x, &y);
		p.push_back (Point (x, y));
	}
	p = convex_hull (p); 
	p.pop_back();
	n = p.size();
	
	int ii = 0, jj = 1, kk = 2;
	long long res = Area (p[ii], p[jj], p[kk]);
	while (1) {
		bool check = 0;
		for (int i = 0; i < n; i++) {
			long long areaNow = Area (p[ii], p[jj], p[i]);
			if (areaNow > res) {
				res = areaNow;
				kk = i;
				check = 1;
            }
		}
		for (int i = 0; i < n; i++) {
			long long areaNow = Area (p[ii], p[kk], p[i]);
			if (areaNow > res) {
				res = areaNow;
				jj = i;
				check = 1;
            }
		}
		for (int i = 0; i < n; i++) {
			long long areaNow = Area (p[jj], p[kk], p[i]);
			if (areaNow > res) {
				res = areaNow;
				ii = i;
				check = 1;
            }
		}
		if (!check) break;
	}
	
	Point a = make_pair (p[ii].x + p[jj].x - p[kk].x, p[ii].y + p[jj].y - p[kk].y);
	Point b = make_pair (p[jj].x + p[kk].x - p[ii].x, p[jj].y + p[kk].y - p[ii].y);
	Point c = make_pair (p[kk].x + p[ii].x - p[jj].x, p[kk].y + p[ii].y - p[jj].y);
	printf ("%lld %lld\n%lld %lld\n%lld %lld\n", a.x, a.y, b.x, b.y, c.x, c.y);
    return 0;
}