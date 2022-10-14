#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
bool prime (long long a)
{
	long long b=2;
	while (b*b<=a)
	{
		if (a%b==0) return false;
		b++;
	}
	return true;
}
int main ()
{
	long long n;
	cin>>n;
	if (prime(n)) cout<<"1\n";
	else if (n%2==1) 
	{
		if (prime(n-2)) cout<<"2\n";
		else cout<<"3\n";
	}
	else cout<<"2\n";
}