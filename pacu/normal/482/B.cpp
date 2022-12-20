#include <iostream>
using namespace std;

struct constraint
{
	int l,r;
	bool q;
};

constraint A[100000][30];
int aDif[100001];
bool aOne[100000];
int aCurTot[100000];
int aAns[100000];
int main()
{
	int N,M;
	cin >> N >> M;
	int l,r,q;
	for(int i=0;i<N;i++)
		aAns[i] = 0;
	for(int i=0;i<M;i++)
	{
		cin >> l >> r >> q;
		for(int j=0;j<30;j++)
		{
			A[i][j].l = l-1;
			A[i][j].r = r-1;
			A[i][j].q = (q>>j)&1;
		}
	}
	for(int k=0;k<30;k++)
	{
		for(int i=0;i<N;i++)
			aDif[i] = 0;
		for(int i=0;i<M;i++)
		{
			if(A[i][k].q)
			{
				aDif[A[i][k].l]++;
				aDif[A[i][k].r+1]--;
			}
		}
		int cnt = 0;
		for(int i=0;i<N;i++)
		{
			cnt += aDif[i];
			aOne[i] = (cnt>0);
			aAns[i] += aOne[i]<<k;
		}
		aCurTot[0] = 0;
		for(int i=1;i<=N;i++)
			aCurTot[i] = aCurTot[i-1]+aOne[i-1];
		for(int i=0;i<M;i++)
		{
			if(!A[i][k].q)
				if((aCurTot[A[i][k].r+1]-aCurTot[A[i][k].l])==(A[i][k].r+1-A[i][k].l))
				{
					cout << "NO" << endl;
					return 0;
				}
		}
	}
	cout << "YES" << endl;
	for(int i=0;i<N;i++)
		cout << aAns[i] << " ";
	return 0;
}