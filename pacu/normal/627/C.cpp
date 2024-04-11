#include <iostream>
#include <algorithm>
using namespace std;
#define SEG (1<<18)
int segMin[2*SEG],l[2*SEG],r[2*SEG];

int D,N,M;
long long x[200002],p[200002];
int cid[200002];
long long tmpx[200002],tmpp[200002];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		if(i-SEG <= M+1) segMin[i] = i-SEG;
		else segMin[i] = M+1;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		if(p[segMin[2*i]] <= p[segMin[2*i+1]])
			segMin[i] = segMin[2*i];
		else
			segMin[i] = segMin[2*i+1];
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

int low,high;
int getMin(int i)
{
	if((l[i]>high)||(r[i]<low)) return M+1;
	if((l[i]>=low)&&(r[i]<=high)) 
	{
		return segMin[i];
	}
	int a = getMin(2*i);
	int b = getMin(2*i+1);
	if(p[a]<=p[b]) return a;
	return b;
}

long long divCon(int start,int fin)
{
	//cout << start << ' ' << fin <<'\n';
	if(fin-start == 1)
	{
		if(x[fin]-x[start] <= N) return 0;
		else return -1;
	}
	low = start+1, high = fin-1;
	int mid = getMin(1);
	//cout << mid << '\n';
	long long c1,c2;
	long long spare;
	if(x[mid]-x[start] <= N) c1 = 0, spare = N-(x[mid]-x[start]);
	else c1 = divCon(start,mid), spare = 0;
	if(c1==-1) return -1;
	if(x[fin]-x[mid] <= N) c2 = max(0LL,p[mid]*(x[fin]-x[mid]-spare));
	else
	{
		c2 = divCon(mid,fin);
		if(c2==-1) return -1;
		c2 += max(0LL,p[mid]*(N-spare));
	}
	if(c2==-1) return -1;
	//cout << "cost " << c1 << ' ' << c2 << '\n';
	return c1+c2;
}

bool cmp(int a,int b)
{
	return x[a]<x[b];
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> D >> N >> M;
	x[0] = 0;
	p[0] = 1000000000000;
	x[M+1] = D;
	p[M+1] = 1000000000000;
	cid[M+1] = M+1;
	for(int i=1;i<=M;i++)
	{
		cin >> x[i] >> p[i];
		cid[i] = i;
	}
	sort(cid,cid+M+2,cmp);
	for(int i=0;i<=M+1;i++)
		tmpx[i] = x[cid[i]], tmpp[i] = p[cid[i]];
	for(int i=0;i<=M+1;i++)
	{
		x[i] = tmpx[i], p[i] = tmpp[i];
	}
	init();
	cout << divCon(0,M+1) << '\n';
}