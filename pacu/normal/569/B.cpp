#include <iostream>
#include <vector>
using namespace std;

int A[100000];
int n;

bool vis[100000];
vector<int> av;

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> A[i];
		A[i]--;
		vis[A[i]] = 1;
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
			av.push_back(i);
	for(int i=0;i<n;i++)
		vis[i] = 0;
	for(int i=0;i<n;i++)
	{
		if(!vis[A[i]])
		{
			vis[A[i]] = 1;
		}
		else
		{
			A[i] = av.back();
			av.pop_back();
			vis[A[i]] = 1;
		}
		cout << A[i]+1 << ' ';
	}
	cout << '\n';
}