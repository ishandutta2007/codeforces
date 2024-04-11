#include <iostream>
using namespace std;

struct flam
{
	long long x,y;
};

long long best[1000001];

int main()
{
	int N,nFlam;
	flam A[250];
	cin >> N >> nFlam;
	for(int i=1;i<=N;i++)
		best[i] = 1;
	for(int i=0;i<nFlam;i++)
		cin >> A[i].x >> A[i].y;
	for(int i=0;i<nFlam;i++)
		for(int j=0;j<nFlam;j++)
		{
			if(i==j) continue;
			long long b = A[i].x*(A[i].y-A[j].y) - A[i].y*(A[i].x-A[j].x);
			if(A[i].y==A[j].y) continue;
			if(b%(A[i].y-A[j].y)) continue;
			long long cur = b/(A[i].y-A[j].y);
			if(cur<1) continue;
			if(cur>N) continue;
			long long mx = 0;
			for(int k=0;k<nFlam;k++)
				if((A[k].y*(A[i].x-A[j].x))==(((A[i].y-A[j].y)*A[k].x)-b))
					mx++;
			best[cur] = max(best[cur],mx);
		}
	long long ans = 0;
	for(int i=1;i<=N;i++)
		ans += best[i];
	cout << ans << endl;
}