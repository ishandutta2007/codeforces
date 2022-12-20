#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

vector<int> pds[200001];
int A[200000];

int rmax[200000];	//largest value with given remainder
int good[400000];

int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=1;i<N;i++)
		pds[gcd(i,N)].push_back(i);
	long long ans = 0;
	for(int i=1;i<N;i++)
	{
//		cout << i << '\n';
		if(pds[i].size()==0) continue;
		for(int j=0;j<i;j++) rmax[j] = 0;
		int r=0;
		for(int j=0;j<N;j++,r=(r+1)%i) rmax[r] = max(rmax[r],A[j]);
		good[2*N-1] = (A[N-1]==rmax[(N-1)%i]);
		for(int j=2*N-2;j>=N;j--)
		{
			if(A[j-N]==rmax[(j-N)%i])
				good[j] = good[j+1]+1;
			else
				good[j] = 0;
		}
		for(int j=N-1;j>=0;j--)
		{
			if(A[j]==rmax[j%i])
				good[j] = good[j+1]+1;
			else
				good[j] = 0;
		}
		for(int j=0;j<N;j++)
		{
//			cout << '\t' << good[j] << '\n';
			if(good[j])
				ans += upper_bound(pds[i].begin(),pds[i].end(),good[j])-pds[i].begin();
		}
	}
	cout << ans << '\n';
}