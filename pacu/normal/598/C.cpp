#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;



int x[100000],y[100000];
long double theta[100000];
int cid[100000];

bool cmp(int a,int b)
{
	return theta[a]<theta[b];
}

long double angle(long double a,long double b)
{
	long double c = a-b;
	if(c<0) c += 2*3.14159265358979323846264338327950288;
	return min(c,2*3.14159265358979323846264338327950288-c);
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> y[i];
		theta[i] = atan2(y[i],x[i]);
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	int best1 = 0;
	int best2 = 1;
	long double cans = 100000;
	for(int i=1;i<2*N;i++)
		if(angle(theta[cid[(i+1)%N]],theta[cid[i%N]]) < cans)
		{
			cans = angle(theta[cid[(i+1)%N]],theta[cid[i%N]]);
			best1 = cid[i%N];
			best2 = cid[(i+1)%N];
		}
	cout << 1+best1 << ' ' << 1+best2 << '\n';
}