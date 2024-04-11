#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int l[100];
int a[101];
bool used[101];

int main()
{
	cin >> N >> M;
	for(int i=0;i<M;i++)
		cin >> l[i];
	for(int i=0;i<M-1;i++)
	{
		if(a[l[i]]!=0)
		{
			if(a[l[i]]%N != (l[i+1]+N-l[i])%N)
			{
				cout << -1 << '\n';
				return 0;
			}
			continue;
		}
		a[l[i]] = (l[i+1]+N-l[i])%N;
		if(a[l[i]]==0) a[l[i]] = N;
		if(used[a[l[i]]])
		{
			cout << -1 << '\n';
			return 0;
		}
		used[a[l[i]]] = 1;
	}
	int j = 1;
	for(int i=1;i<=N;i++)
		if(a[i]==0)
		{
			while(used[j]) j++;
			a[i] = j;
			used[j] = 1;
		}
	for(int i=1;i<=N;i++)
		cout << a[i] << ' ';
	cout << '\n';
}