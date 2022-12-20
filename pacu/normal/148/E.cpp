#include <iostream>
#include <vector>
using namespace std;

struct Shelf
{
	vector<int> aVal;
	vector<int> aDam;	//max damage inflicted by k shrieks
	int sz;
};

int dp[101][10001];	//best damage from first i shelves and only k shrieks

int main()
{
	int nShelves;
	int M;
	vector<Shelf> A;
	int i,j,k;
	int iLeft,iRight;

	cin >> nShelves >> M;
	for(i=0;i<nShelves;i++)
	{
		A.push_back(Shelf());
		cin >> A[i].sz;
		for(j=0;j<A[i].sz;j++)
		{
			A[i].aVal.push_back(0);
			cin >> A[i].aVal[j];
		}
	}
	int bestDam,cDam;
	for(i=0;i<nShelves;i++)
	{
		for(k=0;k<=A[i].sz;k++)
		{
			cDam = 0;
			bestDam = 0;
			for(iLeft=0;iLeft<k;iLeft++)
				cDam += A[i].aVal[iLeft];
			for(iLeft=(k-1),iRight=(A[i].sz-1);iLeft>=0;iLeft--,iRight--)
			{
				if(cDam>bestDam) bestDam = cDam;
				cDam -= A[i].aVal[iLeft];
				cDam += A[i].aVal[iRight];
			}
			if(cDam>bestDam) bestDam = cDam;
			A[i].aDam.push_back(bestDam);
		}
	}
	for(k=0;k<=M;k++)
		dp[0][k] = 0;
	for(i=0;i<nShelves;i++)
	{
		for(k=0;k<=M;k++)	//total number of shrieks so far
		{
			dp[i+1][k] = 0;
			for(j=0;j<=min(A[i].sz,k);j++)	//number of shrieks for current shelf
			{
				if(dp[i+1][k] < (dp[i][k-j] + A[i].aDam[j]))
					dp[i+1][k] = dp[i][k-j] + A[i].aDam[j];
			}
		}
	}
	cout << dp[nShelves][M] << endl;
}