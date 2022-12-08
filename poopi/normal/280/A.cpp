										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>

using namespace std;

#define Pi acos(-1.)
#define int64 long long
#define EPS 1e-9

bool eq(double a, double b){
	return fabs(a - b) < EPS;
}

bool lw(double a, double b){
	return a + EPS < b;
}

bool gr(double a, double b){
	return a - EPS > b;
}

struct Pt{
	double x, y;
	Pt(){x = y = 0;}
	Pt(double _x, double _y){
		x = _x, y = _y;
	}
	bool operator < (const Pt a) const{
		if(!eq(x, a.x))
			return lw(x, a.x);
		return lw(y, a.y);
	}
};

bool leftTurn( Pt a, Pt b, Pt c ){
    return ( b.x - a.x ) * ( c.y - b.y ) - ( b.y - a.y ) * ( c.x - b.x ) > EPS;
}

bool Equal(Pt a, Pt b){
	return eq(a.x, b.x) && eq(a.y, b.y);
}

bool lineIntersect( Pt a, Pt b, Pt c, Pt d, Pt &r ){
    Pt n; n.x = d.y - c.y; n.y = c.x - d.x;
    double denom = n.x * ( b.x - a.x ) + n.y * ( b.y - a.y );
    if( fabs( denom ) < EPS ) return false;
    double num = n.x * ( a.x - c.x ) + n.y * ( a.y - c.y );
    double t = -num / denom;
    r.x = a.x + t * ( b.x - a.x );
    r.y = a.y + t * ( b.y - a.y );
    return true;
}

void cutPoly(list<Pt> &poly, Pt a, Pt b){
	list<Pt> result;
	if(poly.size() == 0)
		return;
	if(poly.size() == 1)
	{
		if(leftTurn(a, b, poly.back()))
			result.push_back(poly.back());
		poly = result;
		return;
	}
	#define LI list<Pt>::iterator 
	LI last = poly.end(); last--;
	bool lastin = leftTurn(a, b, *last);
	for(LI it = poly.begin(); it != poly.end(); it++)
	{
		bool thisin = leftTurn(a, b, *it);
		if(!thisin && lastin || thisin && !lastin)
		{
			Pt r;
			lineIntersect(a, b, *last, *it, r);
			result.push_back(r);
		}
		if(thisin)
			result.push_back(*it);
		last = it;
		lastin = leftTurn(a, b, *last);
	}
	poly.clear();
	Pt Last;
	for(LI it = result.begin(); it != result.end(); it++)
	{
		if(!(it != result.begin() && Equal(*it, Last)))
			poly.push_back(*it);
		Last = *it;
	}
	if(poly.size() > 1)
	{
		if(Equal(poly.front(), poly.back()))
			poly.pop_back();
	}
}

double polygonArea(int n, double x[], double y[]){
	double a = 0;
	for (int i = 1; i <= n; i++){
		a += (x[i - 1] * y[i % n] - x[i % n] * y[i - 1]);
	}
	return a / 2;
}

int n;
double x[50], y[50];
double w, h, a, res;
int dir[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

int main(){
	int aa;
	cin >> w >> h >> aa;
	if(aa > 90)
		a = 180 - aa;
	else a = aa;
	a *= Pi / 180;
	list <Pt> ls;
	for(int i = 0; i < 4; i++)
		ls.push_back(Pt(dir[i][0] * w / 2, dir[i][1] * h / 2));

	Pt pnt[4];
	for(int i = 0; i < 4; i++){
		double x = dir[i][0] * w / 2;
		double y = dir[i][1] * h / 2;
		double dif = sqrt(x * x + y * y);
		double alp = atan2(y, x) + a;
		x = dif * cos(alp);
		y = dif * sin(alp);
		pnt[i] = Pt(x, y);
	}
	for(int i = 0; i < 4; i++)
		cutPoly(ls, pnt[i], pnt[(i + 1) % 4]);

	n = 0;
	for(list <Pt>::iterator it = ls.begin(); it != ls.end(); it++){
		x[n] = (*it).x;
		y[n++] = (*it).y;
	}

	res = polygonArea(n, x, y);
	cout.precision(8);
	cout.setf(ios::fixed | ios::showpoint);
	cout << res << endl;
	return 0;
}