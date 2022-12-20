#include <iostream>
#include <string>
#include <set>
using namespace std;

long long mod[] = {3001777,3009659,3009977,3001939,3001631,3002507,3002677,3003491,3004307,3004181,
	1509971,1509589,1508723,1507867,1507183,1506731,1506179,1505033,1504297,1501859};
#define B 31

string A;
bool bad[1500];
int N,K;
long long pHash[1501][20];
long long pw[1501][20];

void calc()
{
	for(int k=0;k<20;k++)
	{
		pw[0][k] = 1;
		for(int i=1;i<=N;i++)
			pw[i][k] = (pw[i-1][k]*B)%mod[k];
		pHash[0][k] = 0;
		for(int i=1;i<=N;i++)
			pHash[i][k] = (pHash[i-1][k]*B+(1+A[i-1]-'a'))%mod[k];
	}
}

int range(int i,int j,int k)	//[i,j] mod[k]
{
	return (((pHash[j+1][k]-pw[j+1-i][k]*pHash[i][k])%mod[k])+mod[k])%mod[k];
}

string good;
bool occ[4000000][20];

int main()
{
	ios::sync_with_stdio(0);
	cin >> A >> good >> K;
	N = A.size();
	for(int i=0;i<N;i++)
		bad[i] = (good[A[i]-'a']=='0');
	calc();
	int ans = 0;
	int a[20];
	bool added;
	for(int i=0;i<N;i++)
	{
		int cbad = 0;
		for(int j=i;j>=0;j--)
		{
			cbad += bad[j];
			if(cbad > K)
				break;
			added = 0;
			for(int k=0;k<15;k++)
			{
				a[k] = range(j,i,k);
				if(!added && !occ[a[k]][k])
				{
					ans++;
					added = 1;
				}
				occ[a[k]][k] = 1;
			}
		}
	}
	cout << ans << endl;
}