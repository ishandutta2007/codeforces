#include <iostream>
#include <algorithm>
using namespace std;

struct fr
{
	int m,f;
};

bool cmp(fr a,fr b)
{
	return a.m < b.m;
}

fr A[100000];
int N,D;

int main()
{
	cin >> N >> D;
	for(int i=0;i<N;i++)
		cin >> A[i].m >> A[i].f;
	sort(A,A+N,cmp);
	int j = 0;
	long long sm = 0;
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		sm += A[i].f;
		while(A[i].m-A[j].m >= D)
		{
			sm -= A[j].f;
			j++;
		}
		ans = max(ans,sm);
	}
	cout << ans << '\n';
}