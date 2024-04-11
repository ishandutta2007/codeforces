#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N,M;
string A[50];

int fid[100];

void init()
{
	for(int i=0;i<100;i++)
		fid[i] = i;
}

int find(int i)
{
	if(fid[i]==i) return i;
	return fid[i] = find(fid[i]);
}

void join(int i,int j)
{
	i = find(i), j = find(j);
	fid[i] = j;
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> A[i];
	init();
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(A[i][j]=='#')
				join(2*i,2*j+1);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(find(2*i) == find(2*j+1) && A[i][j]=='.')
			{
				cout << "NO\n";
				return 0;
			}
	cout << "YES\n";
	return 0;
}