#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string s,string t)
{
	return s+t<t+s;
}

string A[50000];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N,cmp);
	for(int i=0;i<N;i++)
		cout << A[i];
	cout << '\n';
}