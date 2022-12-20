#include <iostream>
#include <vector>
using namespace std;
int op[100][100];
int main()
{
	int N,M,K;
	int n,m,k;
	int memLocked[101];
	int procLocked[101];
	int memOccupied[101];
	int memPrev[101];
	int memPrevCycle[101];
	cin >> N >> M >> K;
	for(k=0;k<=K;k++)
	{
		memLocked[k] = 0;
		memOccupied[k] = 0;
	}
	for(n=0;n<N;n++)
	{
		procLocked[n] = 0;
		for(m=0;m<M;m++)
			cin >> op[n][m];
	}
	for(m=0;m<M;m++)
	{
		for(n=0;n<N;n++)
		{
			if(op[n][m]==0)
				continue;
			if(procLocked[n])
				continue;
			if(memLocked[op[n][m]])
			{
				procLocked[n] = m+1;
				continue;
			}
			if(memOccupied[op[n][m]])
			{
				memLocked[op[n][m]] = 1;
				procLocked[n] = m+1;
				procLocked[memPrev[op[n][m]]] = memPrevCycle[op[n][m]]+1;
				continue;
			}
			memOccupied[op[n][m]]++;
			memPrev[op[n][m]] = n;
			memPrevCycle[op[n][m]] = m;
		}
		for(k=0;k<=K;k++)
			memOccupied[k] = 0;
	}
	for(n=0;n<N;n++)
		cout << procLocked[n] << endl;
}