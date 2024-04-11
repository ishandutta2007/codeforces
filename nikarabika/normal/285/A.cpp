# include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ULL;
typedef long long int LL;

const int maxn=1e6;
int a[maxn];

int main()
{
	int n,k;
	cin >> n >> k;

	for(int i=1 ; i<=n ; i++)
		a[i]=i;

	reverse(a+1,a+k+2);

	for(int i=1 ; i<=n ; i++)
		cout << a[i] <<" ";

	return 0;
}