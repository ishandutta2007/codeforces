#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Point
{
	long long x,y;
};

struct pt
{
	long long x,y;
};

bool operator<(Point a,Point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
bool operator<(pt a,pt b)
{
	return a.y<b.y;
}
int N;
vector<Point> A;

long long getdist(pt a,pt b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

long long findClosest(int start,int end)	//distance for range [start,end)
{
	if((start+1)>=end)
		return (1<<30);
	int mid = (start+end)/2;
	long long dleft = findClosest(start,mid);
	long long dright = findClosest(mid,end);
	long long dmin = min(dleft,dright);
	int lStart,lEnd,rStart,rEnd;
	long long d;
	vector<pt> strip;
	pt p;
	lEnd = mid-1;
	rEnd = mid;
	while((rEnd<end) && ((A[rEnd].x-A[mid].x)<=dmin))
	{
		p.x = A[rEnd].x;
		p.y = A[rEnd].y;
		strip.push_back(p);
		rEnd++;
	}
	while((lEnd>=start) && ((A[mid].x-A[lEnd].x)<=dmin))
	{
		p.x = A[lEnd].x;
		p.y = A[lEnd].y;
		strip.push_back(p);
		lEnd--;
	}
	sort(strip.begin(),strip.end());
	int i,j;
	for(i=0;i<strip.size();i++)
	{
		for(j=i+1;j<strip.size() && j<=(i+7);j++)
		{
			d = getdist(strip[i],strip[j]);
			if(d<dmin)
				dmin = d;
		}
	}
	return dmin;
}

int main()
{
	int N;
	cin >> N;
	Point a;
	int val;
	cin >> a.y;
	a.x = 0;
	A.push_back(a);
	a.x++;
	while(a.x<N)
	{
		cin >> val;
		a.y += val;
		A.push_back(a);
		a.x++;
	}
	sort(A.begin(),A.end());
	cout << findClosest(0,N) << endl;
}