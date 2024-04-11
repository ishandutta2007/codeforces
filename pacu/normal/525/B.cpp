#include <iostream>
#include <string>
using namespace std;

int N;
string s;
int A[200001];

int main()
{
	cin >> s;
	N = s.size();
	int M;
	cin >> M;
	int a;
	for(int i=0;i<M;i++)
	{
		cin >> a;
		a--;
		A[a]++;
		A[N-a]--;
	}
	int cur = 0;
	for(int i=0;i<(N-1-i);i++)
	{
		cur += A[i];
		if(cur%2)
			swap(s[i],s[N-1-i]);
	}
	cout << s << "\n";
	return 0;
}