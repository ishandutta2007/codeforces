#include <iostream>
using namespace std;

int N;
int p[100];

int vis[100];

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return (a/gcd(a,b))*b;
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> p[i];
		p[i]--;
	}
	long long g = 1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++) vis[j] = 0;
		vis[i] = 1;
		int j = p[i];
		for(int k=2;;k++)
		{
			if(vis[j])
			{
				if(j!=i)
				{
					cout << -1 << '\n';
					return 0;
				}
				g = lcm(g,k-vis[i]);
				break;
			}
			vis[j] = k;
			j = p[j];
		}
	}
	if(g%2==0) g /= 2;
	cout << g << '\n';
}