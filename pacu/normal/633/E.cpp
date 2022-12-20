#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;
#define SEG (1<<20)
int segMin[2*SEG],segMax[2*SEG],l[2*SEG],r[2*SEG];
int N,K;
int v[1000000],c[1000000];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		if(i-SEG<N) segMin[i] = c[i-SEG], segMax[i] = v[i-SEG];
		else segMin[i] = 2000000000, segMax[i] = -2000000000;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		segMin[i] = min(segMin[2*i],segMin[2*i+1]);
		segMax[i] = max(segMax[2*i],segMax[2*i+1]);
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

int low,high;
int getMin(int i)
{
	if((l[i]>high)||(r[i]<low)) return 2000000000;
	if((l[i]>=low)&&(r[i]<=high)) return segMin[i];
	return min(getMin(2*i),getMin(2*i+1));
}
int getMax(int i)
{
	if((l[i]>high)||(r[i]<low)) return -2000000000;
	if((l[i]>=low)&&(r[i]<=high)) return segMax[i];
	return max(getMax(2*i),getMax(2*i+1));
}

int val[1000000];
int lastlow,lasthigh;

int lowval(int a,int b)
{
	low = a,high = b;
	lastlow = getMin(1);
	return lastlow;
}
int highval(int a,int b)
{
	low = a,high = b;
	lasthigh = getMax(1);
	return lasthigh;
}

double prob[1000000];

int main()
{
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&v[i]);
		v[i] = 100*v[i];
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&c[i]);
	}
	init();
	int j = N-1;
	for(int i=N-1;i>=0;i--)
	{
		while(lowval(i,j) < highval(i,j))
			j--;
		val[i] = min(lastlow,lasthigh);
		if(j<N-1) val[i] = max(val[i],min(lowval(i,j+1),highval(i,j+1)));
//		cout << val[i] << '\n';
	}
	double ans = 0;
	prob[0] = 1;
	double cp = 1;
	for(int i=1;i<N;i++)
	{
		cp *= N-K-i+1;
		cp /= N-i+1;
		prob[i] = cp;
	}
	for(int i=0;i<N-1;i++)
		prob[i] -= prob[i+1];
	sort(val,val+N);
	for(int i=0;i<N;i++)
		ans += prob[i]*val[i];
	printf("%.20f\n",ans);
}