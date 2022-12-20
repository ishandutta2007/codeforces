#include <iostream>
using namespace std;

int A[5000];
int N;
int nodes;
long long add;
long long dfs(int i)
{
	if((2*i)>=nodes)
		return 0;
	long long a = A[2*i]+dfs(2*i+1);
	long long b = A[2*i+1]+dfs(2*i+2);
	add += abs(a-b);
	return max(a,b);
}

int main()
{
	cin >> N;
	nodes = ((1<<(N+1)))-2;
	int sm = 0;
	for(int i=0;i<nodes;i++)
	{
		cin >> A[i];
		sm += A[i];
	}
	add = 0;
	dfs(0);
	cout << add << "\n";
	return 0;
}