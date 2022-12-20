#include <iostream>
using namespace std;

#define SEG (1<<17)
int seg[2*SEG];
int l[2*SEG];
int r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = 0;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = 0;
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

void update(int i,int v)
{
	i += SEG;
	seg[i] = v;
	for(i/=2;i>0;i/=2)
		seg[i] = max(seg[2*i],seg[2*i+1]);
}

int getMax(int i,int low,int high)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return max(getMax(2*i,low,high),getMax(2*i+1,low,high));
}

int A[100000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	init();
	int best = 0;
	int cur;
	for(int i=0;i<N;i++)
	{
		cur = getMax(1,0,A[i]);
		update(A[i],cur+1);
		best = max(best,cur+1);
	}
	cout << best << endl;
	return 0;
}