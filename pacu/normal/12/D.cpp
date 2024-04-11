#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int B[500000],I[500000],R[500000];

#define SEG (1<<19)
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
		l[i] = l[2*i];
		r[i] = r[2*i+1];
		seg[i] = -1;
	}
}

void update(int i,int v)
{
	i += SEG;
	seg[i] = max(seg[i],v);
	for(i>>=1;i>0;i>>=1)
		seg[i] = max(seg[2*i],seg[2*i+1]);
}

int low,high;
int getHigh(int i)
{
	if((l[i]>high)||(r[i]<low)) return -1;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return max(getHigh(i<<1),getHigh((i<<1)+1));
}

int cid[500000];

bool cmpB(int a,int b)
{
	return B[a]>B[b];
}

bool cmpI(int a,int b)
{
	return I[a]<I[b];
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		cin >> B[i];
	for(int i=0;i<N;i++)
		cin >> I[i];
	for(int i=0;i<N;i++)
		cin >> R[i];
	for(int i=0;i<N;i++)
		cid[i] = i;
	sort(cid,cid+N,cmpI);
	int c = 0;
	int pre = I[cid[0]];
	for(int i=0;i<N;i++)
	{
		if(I[cid[i]] != pre)
			c++;
		pre = I[cid[i]];
		I[cid[i]] = c;
	}
	sort(cid,cid+N,cmpB);
	int ans = 0;
	init();
	high = c;
	for(int i=0;i<N;i++)
	{
		low = I[cid[i]]+1;
		if(getHigh(1) > R[cid[i]])
			ans++;
		if((i==(N-1))||(B[cid[i]] != B[cid[i+1]]))
			for(int j=i;(j>=0)&&(B[cid[i]]==B[cid[j]]);j--)
				update(I[cid[j]],R[cid[j]]);
	}
	printf("%d\n",ans);
	return 0;
}