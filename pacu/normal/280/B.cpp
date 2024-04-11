#include <iostream>
using namespace std;

int stack[100000];
int A[100000];
int N;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int best = 0;
	int ss = 0;
	for(int i=0;i<N;i++)
	{
		while((ss>0)&&(stack[ss-1] < A[i]))
		{
			best = max(best,stack[ss-1]^A[i]);
			ss--;
		}
		if(ss>0)
			best = max(best,stack[ss-1]^A[i]);
		stack[ss++] = A[i];
	}
	cout << best << "\n";
	return 0;
}