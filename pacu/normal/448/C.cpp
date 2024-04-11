#include <iostream>
#include <vector>
using namespace std;
vector<int> A;
int N;

int solve(int a,int b)
{
	while(A[a]==0)
		a++;
	int ans = (b-a)+1;
	int mn = 1+1e9;
	for(int i=a;i<=b;i++)
		mn = min(mn,A[i]);
	int firstPos = 0;
	int i;
	int tot = mn;
	for(i=a;i<=b;i++)
		A[i] -= mn;
	for(i=(a+1);i<=b;i++)
	{
		if((A[i]==0)&&(A[i-1]>0))
		{
			tot += solve(firstPos,i-1);
			firstPos = i;
		}
	}
	if(A[b]>0)
		tot += solve(firstPos,b);
	return min(ans,tot);
}

int main()
{
	int i,j;
	cin >> N;
	for(i=0;i<N;i++)
	{
		A.push_back(0);
		cin >> A[i];
	}
	cout << solve(0,N-1) << endl;
}