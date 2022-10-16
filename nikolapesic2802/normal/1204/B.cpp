#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;

int main()
{
	int n,l,r;
	cin >> n >> l >> r;
	int sum=0,tr=1;
	while(l--)
		sum+=tr,tr*=2,r--,n--;
	cout << sum+n << " ";
	while(r--)
		sum+=tr,tr*=2,n--;
	tr/=2;
	cout << sum+n*tr;
}