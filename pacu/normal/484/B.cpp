#include <iostream>
using namespace std;
#define MAXN 2000001

bool used[MAXN];
bool cnt[MAXN];
int last[MAXN];
int A[200000];
int N;
int high;
int best;

int main()
{
	for(int i=0;i<MAXN;i++)
		cnt[i] = used[i] = false;
	cin >> N;
	high = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		high = max(high,A[i]);
		cnt[A[i]] = true;
	}
	last[0] = -1;
	for(int i=0;i<(MAXN-1);i++)
	{
		if(cnt[i])
			last[i+1] = i;
		else
			last[i+1] = last[i];
	}
	best = 0;
	for(int i=0;i<N;i++)
	{
		if(used[A[i]])
			continue;
		int j = 2*A[i];
		while(j < 2*high)
		{
			best = max(best,last[j]%A[i]);
			j += A[i];
		}
		used[A[i]] = 1;
	}
	cout << best << endl;
}