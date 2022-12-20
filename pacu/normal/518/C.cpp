#include <iostream>
using namespace std;

int P[100000];	//N
int query[100000];	//M
int pos[100000];

int main()
{
	int N,M,K;
	cin >> N >> M >> K;
	for(int i=0;i<N;i++)
	{
		cin >> P[i];
		P[i]--;
		pos[P[i]] = i;
	}
	long long tot = 0;
	int q,prev;
	for(int i=0;i<M;i++)
	{
		cin >> q;
		q--;
		tot += 1+(pos[q]/K);
		if(pos[q] != 0)
		{
			prev = P[pos[q]-1];
			swap(P[pos[q]-1],P[pos[q]]);
			pos[q]--;
			pos[prev]++;
		}
	}
	cout << tot << endl;
	return 0;
}