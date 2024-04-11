#include <iostream>
using namespace std;

int nVal;
int cnt[1000001];
int A[1000000];
int N,K;

void add(int i)
{
	if(cnt[A[i]]==0) nVal++;
	cnt[A[i]]++;
}
void remove(int i)
{
	cnt[A[i]]--;
	if(cnt[A[i]]==0) nVal--;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	nVal = 0;
	int bestl = 0;
	int bestr = 0;
	int j = 0;
	for(int i=0;i<N;i++)
	{
		add(i);
		while(nVal>K)
		{
			remove(j);
			j++;
		}
		if(i-j > bestr-bestl)
			bestl = j, bestr = i;
	}
	cout << bestl+1 << ' ' << bestr+1 << '\n';
}