#include <iostream>
#include <map>
using namespace std;

map<int,int> M;
long long posSum[300001];
int A[300001];

int main()
{
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> A[i];
	posSum[0] = 0;
	for(int i=1;i<=N;i++)
	{
		if(A[i]<0) posSum[i] = posSum[i-1];
		else posSum[i] = posSum[i-1]+A[i];
	}
	int a = 1;
	int b = N;
	long long best = -1000000000000000LL;
	long long cur;
	for(int i=1;i<=N;i++)
	{
		if(M.find(A[i]) != M.end())
		{
			if(A[i]<0) cur = 2LL*A[i] + posSum[i] - posSum[M[A[i]]];
			else cur = posSum[i] - posSum[M[A[i]]-1];
//			cout << i << " " << posSum[i-1] << posSum[M[A[i]]-1] << endl;
			if(best < cur)
			{
				best = cur;
				a = M[A[i]];
				b = i;
			}
		}
		else
			M[A[i]] = i;
	}
	int cnt = 0;
	for(int i=1;i<=N;i++)
	{
		if((i<a)||(i>b)||((i>a)&&(i<b)&&(A[i]<0)))
			cnt++;
	}
	cout << best << " " << cnt << "\n";
	for(int i=1;i<=N;i++)
		if((i<a)||(i>b)||((i>a)&&(i<b)&&(A[i]<0)))
			cout << i << " ";
	cout << "\n";
	return 0;
}