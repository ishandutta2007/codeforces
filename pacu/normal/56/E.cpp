#include <iostream>
#include <algorithm>
using namespace std;
#define SEG (1<<17)

int x[100000];
int h[100000];
int cid[100000];
int ans[100000];

int seg[2*SEG],l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = -1;
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
	if((l[i]>high)||(r[i]<low)) return -1;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return max(getMax(2*i,low,high),getMax(2*i+1,low,high));
}

bool cmp(int a,int b)
{
	return x[a]<x[b];
}

int binSearch(int low,int high,int v)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(x[cid[high]] < v) return high;
		return low;
	}
	int mid = (low+high)>>1;
	if(x[cid[mid]] < v) return binSearch(mid,high,v);
	else return binSearch(low,mid-1,v);
}

int main()
{
	init();
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x[i] >> h[i];
		cid[i] = i;
	}
	sort(cid,cid+N,cmp);
	int j = N-1;
	update(N-1,N-1);
	ans[cid[N-1]] = 1;
	int lst;
	for(int i=N-2;i>=0;i--)
	{
		j = binSearch(i,N-1,x[cid[i]]+h[cid[i]]);
		if(j>i)
			lst = getMax(1,i+1,j);
		else
			lst = i;
		update(i,lst);
		ans[cid[i]] = 1+lst-i;
	}
	for(int i=0;i<N;i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}