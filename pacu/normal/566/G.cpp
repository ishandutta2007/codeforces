#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
	long long x,y;
};

bool cmp(Point a,Point b)
{
	if(a.x==b.x)
		return a.y>b.y;
	return a.x<b.x;
}

bool getCross(Point &O,Point &A,Point &B)
{
	return (O.x-A.x)*(O.y-B.y) > (O.x-B.x)*(O.y-A.y);
}

vector<int> hull;

Point minA[100002];
Point maxA[100000];
int N,M;

void getHull()
{
	long long highy = 0;
	long long highx = 0;
	for(int i=0;i<M;i++)
		highy = max(highy,minA[i].y), highx = max(highx,minA[i].x);
	minA[M].x = -1, minA[M].y = highy, minA[M+1].x = highx, minA[M+1].y = -1;
	sort(minA,minA+M+2,cmp);
	sort(maxA,maxA+N,cmp);
	for(int i=0;i<M+2;i++)
	{
		if((i>0) && minA[i].x == minA[i-1].x && minA[i].y != -1) continue;
		while(hull.size() >= 2 && getCross(minA[hull[hull.size()-2]],minA[hull[hull.size()-1]],minA[i]))
			hull.pop_back();
		hull.push_back(i);
	}
}

int main()
{
	int x,y;
	cin >> N >> M >> x >> y;
	for(int i=0;i<N;i++)
		cin >> maxA[i].x >> maxA[i].y;
	for(int i=0;i<M;i++)
		cin >> minA[i].x >> minA[i].y;
	getHull();
//	for(int i=0;i<hull.size();i++)
//		cout << minA[hull[i]].x << ' ' << minA[hull[i]].y << '\n';
	int j = 0;
	for(int i=0;i<N;i++)
	{
		while(j<hull.size() && maxA[i].x >= minA[hull[j]].x)
			j++;
		if(j == hull.size())
		{
			cout << "Max\n";
			return 0;
		}
		if(minA[hull[j]].x == minA[hull[j-1]].x)
		{
			if(maxA[i].x >= minA[hull[j]].x)
			{
				cout << "Max\n";
				return 0;
			}
		}
		else if((maxA[i].y - minA[hull[j-1]].y)*(minA[hull[j]].x - minA[hull[j-1]].x) >= (maxA[i].x - minA[hull[j-1]].x)*(minA[hull[j]].y - minA[hull[j-1]].y))
		{
//			cout << (maxA[i].y - minA[hull[j-1]].y)*(minA[hull[j]].x - minA[hull[j-1]].x) << '\n';
//			cout << minA[hull[j]].y << '\n';
			cout << "Max\n";
			return 0;
		}
	}
	cout << "Min\n";
	return 0;
}