#include <iostream>
#include <map>
using namespace std;

map<int,int> nEdges;
map<int,int> A;
map<int,int> B;

int x[100000];
int y[100000];

int main()
{
	int N;
	int a,b;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		if(nEdges[a] == 0) A[a] = b;
		else B[a] = b;
		if(nEdges[b] == 0) A[b] = a;
		else B[b] = a;
		nEdges[a]++;
		nEdges[b]++;
		x[i] = a;
		y[i] = b;
	}
	int cur;
	for(int i=0;i<N;i++)
	{
		if(nEdges[x[i]]==1) cur = x[i];
		if(nEdges[y[i]]==1) cur = y[i];
	}
	int nxt;
	while(1)
	{
		if(cur==0)
			break;
		cout << cur << " ";
		nxt = A[cur];
		if(A[nxt] == cur)
			A[nxt] = B[nxt];
		cur = nxt;
	}
	cout << endl;
}