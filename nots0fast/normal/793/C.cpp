#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define lli long long int
#define ff first
#define ss second
#define mp make_pair
double eps = pow(10,-11);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	double x1, y1 , x2 ,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1>x2)
	{
		double temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if(y1>y2)
	{
		double temp = y1;
		y1 = y2;
		y2 = temp;
	}
	multimap<double,double> all;
	fori(n)
	{
		double x,y,vx,vy;
		cin>>x>>y>>vx>>vy;
		vector<double> times;
		if( ( ( x==x1 || x==x2 ) && !vx ) ||  ( ( y==y1 || y==y2 ) && !vy ))
		{
			cout<<-1;
			return 0;
		}
		if(x>=x1 && x<=x2 && y>=y1 && y<=y2)
		{
			times.push_back(0);
		}
		if(vx)
		{
			double t = (x1-x)/vx;
			double check = y + vy*t;
			if(check>=y1 && check<=y2 && t>=0) 
			{
				times.push_back(t);
			}
			t = (x2-x)/vx;
			check = y + vy*t;
			if(check>=y1 && check<=y2 && t>=0)
			{
				times.push_back(t);
			}
		}
		if(vy)
		{
			double t = (y1-y)/vy;
			double check = x + vx*t;
			if(check>=x1 && check<=x2 && t>=0)
			{
				times.push_back(t);
			}
			t = (y2-y)/vy;
			check = x + vx*t;
			if(check>=x1 && check<=x2 && t>=0)
			{
				times.push_back(t);
			}
		}
		if(!vx && !vy)
		{
			if(times.size())
			times.push_back(pow(10,9));
		}
		sort(times.begin(),times.end());
		for(int i=1;i<times.size(); i++)
		{
			if(fabs(times[i]-times[i-1])<=eps)
			{
				times.erase(times.begin()+i);
				--i;
			}
		}
		if(times.size()==2)
		{
			all.insert(mp(times[0],times[1]));
		}
	}
	multimap<double,double> :: iterator it = all.begin();
	multiset<double> cixdi;
	int say = 0;
	int maxx = 0;
	double time = -1;
	while(it!=all.end())
	{
		double timo = (*it).ff;
		while(cixdi.size() && timo>=(*cixdi.begin()))
		{
			cout<<-1;
			return 0;
		}
		++say;
		if(say == n && timo>=0)
		{
			time = timo+eps;
			cout<<setprecision(9)<<fixed<<timo;
			return 0;
		}
		cixdi.insert((*it).ss);
		++it;
	}
	cout<<-1;
}