#include <iostream>
using namespace std;

#define SEG (1<<17)

int l[2*SEG],r[2*SEG];
long long segSum[2*SEG];
int segMax[2*SEG];
int A[SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		segSum[i] = A[i-SEG];
		segMax[i] = i-SEG;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		l[i] = l[2*i];
		r[i] = r[2*i+1];
		if(A[segMax[2*i]]>A[segMax[2*i+1]])
			segMax[i] = segMax[2*i];
		else
			segMax[i] = segMax[2*i+1];
		segSum[i] = segSum[2*i]+segSum[2*i+1];
	}
}

void set(int i,long long v)
{
	A[i] = v;
	i += SEG;
	segSum[i] = v;
	for(i/=2;i>0;i/=2)
	{
		if(A[segMax[2*i]]>A[segMax[2*i+1]])
			segMax[i] = segMax[2*i];
		else
			segMax[i] = segMax[2*i+1];		
		segSum[i] = segSum[2*i]+segSum[2*i+1];
	}
}

int getMax(int i,int low,int high)
{
	if((l[i]>high)||(r[i]<low)) return SEG-1;
	if((l[i]>=low)&&(r[i]<=high)) return segMax[i];
	int a = getMax(2*i,low,high);
	int b = getMax(2*i+1,low,high);
	if(A[a] > A[b]) return a;
	return b;
}

long long getSum(int i,int low,int high)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return segSum[i];
	return getSum(2*i,low,high)+getSum(2*i+1,low,high);
}

int main()
{
	A[SEG-1] = -1;
	int N,Q;
	cin >> N >> Q;
	for(int i=0;i<N;i++)
		cin >> A[i];
	init();
	int tp,a,b,c;
	for(int i=0;i<Q;i++)
	{
		cin >> tp >> a >> b;
		if(tp==1)
			cout << getSum(1,a-1,b-1) << endl;
		if(tp==2)
		{
			cin >> c;
			int k = getMax(1,a-1,b-1);
			while(A[k] >= c)
			{
				set(k,A[k]%c);
				k = getMax(1,a-1,b-1);
			}
		}
		if(tp==3)
			set(a-1,b);
	}
}