#include <iostream>
#include <vector>
using namespace std;

int N,K;
int A[300000];
int c0[300000];

vector<int> l;

bool pos(int i,int j)
{
	int z = c0[j];
	if(i) z -= c0[i-1];
	return z <= K;
}

int binSearch(int low,int high,int j)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(pos(low,j)) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(pos(mid,j)) return binSearch(low,mid,j);
	else return binSearch(mid+1,high,j);
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
	}
	c0[0] = (A[0]==0);
	for(int i=1;i<N;i++)
		c0[i] = c0[i-1] + (A[i]==0);
	int ans = 0;
	int bi = 0;
	for(int i=0;i<N;i++)
	{
		int prev = binSearch(0,i+1,i);
		int cur = i+1-prev;
		if(cur > ans)
		{
			ans = cur;
			bi = i;
		}
	}
	for(int j=bi;j>=bi+1-ans;j--)
		A[j] = 1;
	cout << ans << '\n';
	for(int i=0;i<N;i++) cout << A[i] << ' ';
	cout << '\n';
}