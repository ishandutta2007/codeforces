#include <iostream>
#include <vector>

long long abs(long long a)
{
	if(a<0) return -a;
	return a;
}

using namespace std;

int main()
{
	long long N;
	vector<long long> A;
	long long a;
	long long sm = 0;
	long long cdif = 0;
	cin >> N;
	while(cin>>a)
	{
		A.push_back(a);
		sm += a;
	}
	sm = sm/N;
	for(int i=0;i<N-1;i++)
	{
		cdif += abs(sm-A[i]);
		A[i+1] += A[i]-sm;
	}
	cout << cdif << endl;
}