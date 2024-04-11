#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forz(v) for(int z=0; z<v; z++)
#define mp(a,b) make_pair(a,b)
#define ff first
#define lli long long int
#define ss second

int main()
{
	int k, q;
	cin>>k>>q;
	double  probs[10*k+1][k+1];
	probs[1][1] = 1;
	double ka = k;
	for(int i=2; i<10*k+1; i++)
	{
		probs[i][1] = probs[i-1][1]/ka;
		for(int j=2; j<min(i+1,k+1); j++)
		{
			double ja = j;
			probs[i][j] = probs[i-1][j-1]*(ka+1-ja)/ka + probs[i-1][j]*ja/ka;
		}
	}
	fori(q)
	{
		double prob;
		cin>>prob;
		prob/=2000;
		int j =k;
		while(probs[j][k]<prob)
		{
			++j;
		}
		cout<<j<<endl;
	}
}