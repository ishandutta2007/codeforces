#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
int N;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	long long sm = 0;
	int cnt = 0;
	for(int i=0;i<N;i++)
	{
		if(A[i] >= sm)
		{
			sm += A[i];
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}