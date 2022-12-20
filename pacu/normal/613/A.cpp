#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long long xx[100000],yy[100000];

int main()
{
	int N;
	long long px,py;
	long long x,y;
	double maxr = 0;
	double minr = 1000000000.0;
	double r;
	cin >> N >> px >> py;
	for(int i=0;i<N;i++)
	{
		cin >> x >> y;
		r = (x-px)*(x-px) + (y-py)*(y-py);
		maxr = max(maxr,sqrt(r));
		minr = min(minr,sqrt(r));
		xx[i] = x;
		yy[i] = y;
	}
	double cx,cy;
	double ax,ay,bx,by;
	for(int i=0;i<N;i++)
	{
		ax = xx[i]-px, ay = yy[i]-py;
		bx = xx[(i+1)%N]-px,by =yy[(i+1)%N]-py;
		double t = (by*(by-ay)+bx*(bx-ax))/((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
		if(t<0 || t>1) continue;
		cx = t*ax+(1-t)*bx;
		cy = t*ay+(1-t)*by;
		r = cx*cx+cy*cy;
		minr = min(minr,sqrt(r));
		maxr = max(maxr,sqrt(r));
	}
	cout << fixed << setprecision(20) << 3.14159265358979323*(maxr*maxr-minr*minr) << '\n';
}