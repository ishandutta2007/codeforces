#include <iostream>
using namespace std;

int lowend[100001];

int A[100000];
int B[100000];
int N;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		A[i]--;
		B[A[i]] = i;
	}
	int best = 1;
	int cur = 1;
	for(int i=1;i<N;i++)
	{
		if(B[i] > B[i-1])
		{
			cur++;
			best = max(best,cur);
		}
		else
		{
			best = max(best,cur);
			cur = 1;
		}
	}
	cout << N-best << '\n';
}