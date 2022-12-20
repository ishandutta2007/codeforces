#include <iostream>
using namespace std;

long long w[500];
int b[1000];
bool used[500];
int stack[500];
int sStack;

int main()
{
	sStack = 0;
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> w[i];
		used[i] = 0;
	}
	for(int i=0;i<M;i++)
	{
		cin >> b[i];
		b[i]--;
		if(!used[b[i]])
		{
			stack[sStack++] = b[i];
			used[b[i]] = 1;
		}
	}
	long long ans = 0;
	for(int i=0;i<M;i++)
	{
		int j = 0;
		while(stack[j] != b[i])
			j++;
		int temp = stack[j];
		for(int k=(j-1);k>=0;k--)
		{
			ans += w[stack[k]];
			stack[k+1] = stack[k];
		}
		stack[0] = temp;
	}
	cout << ans << endl;
}