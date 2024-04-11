#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string t,p;
int N,M;
int perm[200000];
bool isRem[200000];

bool pos(int num)
{
	for(int i=0;i<N;i++)
		isRem[i] = 0;
	for(int i=0;i<num;i++)
		isRem[perm[i]] = 1;
	int j = 0;
	for(int i=0;i<N;i++)
	{
		if(!isRem[i] && t[i]==p[j])
			j++;
		if(j==M)
			return 1;
	}
	return 0;
}

int main()
{
	cin >> t >> p;
	N = t.size();
	M = p.size();
	for(int i=0;i<N;i++)
	{
		cin >> perm[i];
		perm[i]--;
	}
	int low = 0;
	int high = N;
	while(low!=high)
	{
		int mid = (low+high+1)/2;
		if(pos(mid)) low = mid;
		else high = mid-1;
	}
	cout << low << '\n';
}