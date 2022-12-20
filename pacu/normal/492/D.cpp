#include <iostream>
#include <cmath>
using namespace std;

long long X,Y;
int N;
long long A[100000];
int ans[100000];

bool works(long long t,long long hits)
{
	return ((t/Y)+(t/X))>=hits;
}

long long binSearch(long long low,long long high,long long hits)
{
	if(high==low) return low;
	if((high-low)==1)
	{
		if(works(low,hits)) return low;
		return high;
	}
	long long mid = (high+low)/2;
	if(works(mid,hits)) return binSearch(low,mid,hits);
	else return binSearch(mid+1,high,hits);
}

int main()
{
	cin >> N >> X >> Y;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		long long t = binSearch(0,10e17,A[i]);
		long long remx = t%Y;
		long long remy = t%X;
		if(remx==remy) ans[i] = 0;
		else if(remx < remy) ans[i] = -1;
		else ans[i] = 1;
	}
	for(int i=0;i<N;i++)
	{
		if(ans[i]==0)
			cout << "Both" << endl;
		else if(ans[i]==1)
			cout << "Vova" << endl;
		else
			cout << "Vanya" << endl;
	}
}