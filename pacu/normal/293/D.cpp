#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define MAXN 2000005

int N;
long long x[100000];
long long y[100000];

int cntx[3000000];
//int cnty[3000000];
long long sm0[3000000];
double sm1[3000000];
double sm2[3000000];

double ans;
long long tot;

void addTop(int i,int i2,bool skipStart)
{
//	cout << "add " << i << ' ' << skipStart << '\n';
	for(long long cx=x[i]+skipStart;cx<=x[i2];cx++)
	{
		long long cy = (y[i]*(x[i2]-cx) + y[i2]*(cx-x[i]))/(x[i2]-x[i]);
		cntx[cx] += cy;
		tot += cy;
	}
}

void removeBottom(int i,int i2,bool skipStart)
{
//	cout << "remove " << i << ' ' << skipStart << '\n';
	for(long long cx=x[i]+skipStart;cx<=x[i2];cx++)
	{
		long long cy = (y[i]*(x[i2]-cx) + y[i2]*(cx-x[i]))/(x[i2]-x[i]);
		if(cy*(x[i2]-x[i]) == (y[i]*(x[i2]-cx) + y[i2]*(cx-x[i])))
			cy--;
		cntx[cx] -= cy;
		tot -= cy;
	}
}

void run()
{
	for(int i=0;i<=MAXN;i++)
		cntx[i] = 0;
	tot = 0;
	int j = 0;
	while(1)
	{
		if(x[(j+1)%N] < x[j]) j = (j+1)%N;
		else if(x[(j+N-1)%N] < x[j]) j = (j+N-1)%N;
		else break;
	}
	if(y[(j+1)%N] > y[(j+N-1)%N])
	{
		bool skip = 0;
		for(int i=j;x[(i+1)%N]>=x[i];i=(i+1)%N)
			if(x[(i+1)%N] > x[i])
			{
				addTop(i,(i+1)%N,skip);
				skip = 1;
			}
		skip = 0;
		for(int i=j;x[(i+N-1)%N]>=x[i];i=(i+N-1)%N)
			if(x[(i+N-1)%N] > x[i])
			{
				removeBottom(i,(i+N-1)%N,skip);
				skip = 1;
			}
	}
	else
	{
		bool skip = 0;
		for(int i=j;x[(i+1)%N]>=x[i];i=(i+1)%N)
			if(x[(i+1)%N] > x[i])
			{
				removeBottom(i,(i+1)%N,skip);
				skip = 1;
			}
		skip = 0;
		for(int i=j;x[(i+N-1)%N]>=x[i];i=(i+N-1)%N)
			if(x[(i+N-1)%N] > x[i])
			{
				addTop(i,(i+N-1)%N,skip);
				skip = 1;
			}		
	}
	for(int i=1;i<=MAXN;i++)
	{
		sm0[i] = sm0[i-1] + cntx[i];
		double csm0 = sm0[i-1] + cntx[i]/2.0;
		csm0 /= tot;
		csm0 /= (tot-1);
		sm1[i] = sm1[i-1] + csm0;
		sm2[i] = sm2[i-1] + sm1[i];
		ans += cntx[i]*sm2[i-1];
	}
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> y[i];
		x[i] += 1000001, y[i] += 1000001;
	}
	run();
	for(int i=0;i<N;i++)
		swap(x[i],y[i]);
	run();
	cout << setprecision(20) << 2.0*ans << '\n';
}