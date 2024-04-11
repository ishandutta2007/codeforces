#include <iostream>
#include <vector>
#include <string>
using namespace std;

int low[100000];	//number of lowercase letters (0) before any given point
int high[100000];	//number of uppercase letters (1) after AND INCLUDING any given point

int main()
{
	int N;
	string s;
	vector<int> A;
	int i,j;
	cin >> s;
	N = s.size();
	for(i=0;i<N;i++)
		A.push_back(s[i]<95);
	int best = 0;
	for(i=0;i<N;i++)
		if(!A[i]) best++;
	low[0] = 0;
	for(i=1;i<N;i++)
		low[i] = low[i-1] + (A[i-1]==0);
	high[N-1] = A[N-1];
	for(i=(N-2);i>=0;i--)
		high[i] = high[i+1] + (A[i]==1);
	for(i=0;i<N;i++)
		best = min(best,low[i]+high[i]);
	cout << best << endl;
}