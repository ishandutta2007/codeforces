#include <iostream>
#include <vector>
using namespace std;

int low[100000];
int ans[100000];
int A[100000];

int binSearch(int i,int j,int val)	//highest index with low[i] < val
{
	if(i==j)
		return i;
	if((i+1)==j)
	{
		if(low[j]<val) return j;
		return i;
	}
	int mid = (i+j)/2;
	if(low[mid]>=val)
		return binSearch(i,mid-1,val);
	else
		return binSearch(mid,j,val);
}

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	low[N-1] = A[N-1];
	ans[N-1] = -1;
	for(int i=(N-2);i>=0;i--)
	{
		low[i] = -1;
		int c = binSearch(i,N-1,A[i]);
		if(c==i)
			ans[i] = -1;
		else
			ans[i] = (c-i)-1;
		low[i] = min(A[i],low[i+1]);
	}
	for(int i=0;i<N;i++)
		cout << ans[i] << " ";
	return 0;
}