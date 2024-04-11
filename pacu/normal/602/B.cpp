#include <iostream>
using namespace std;

int N;
int A[100000];

int x,y,bx,by;
int qx[100000],qy[100000];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	x = y = bx = by = 0;
	int best = 0;
	int j = 0;
	for(int i=0;i<N;i++)
	{
		while(x>bx && A[qx[x-1]] <= A[i])
			x--;
		qx[x++] = i;
		while(y>by && A[qy[y-1]] >= A[i])
			y--;
		qy[y++] = i;
		while(A[qx[bx]]-A[qy[by]] > 1)
		{
			if(qx[bx]==j) bx++;
			if(qy[by]==j) by++;
			j++;
		}
		best = max(best,i+1-j);
	}
	cout << best << '\n';
}