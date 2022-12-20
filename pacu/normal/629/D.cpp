#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#define SEG (1<<17)
long long seg[2*SEG],l[2*SEG],r[2*SEG];
void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
		l[i] = l[2*i], r[i] = r[2*i+1];
}
void update(int i,long long val)
{
	i += SEG;
	seg[i] = val;
	for(i/=2;i>0;i/=2)
		seg[i] = max(seg[2*i],seg[2*i+1]);
}
int low,high;
long long getMax(int i)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return max(getMax(2*i),getMax(2*i+1));
}

long long v[100000];
int N;

int cid[100000];
bool cmp(int a,int b)
{
	if(v[a]==v[b]) return a>b;
	return v[a]<v[b];
}

int main()
{
	cin >> N;
	long long r,h;

	for(int i=0;i<N;i++)
	{
		cin >> r >> h;
		v[i] = r*r*h;
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	long long ans = 0;
	init();
	for(int i=0;i<N;i++)
	{
		low = 0, high = cid[i];
		long long cur = getMax(1)+v[cid[i]];
		ans = max(ans,cur);
		update(cid[i],cur);
	}
	cout << setprecision(20) << ((double)ans)*3.14159265358979 << '\n';
}