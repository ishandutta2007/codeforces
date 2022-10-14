#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define fi first
#define se second
#define debug printf
using namespace std;
int sub (int a)
{
	if (a%10==0) return a/10;
	else return a-1;
}
int main ()
{
	int n, k;
	scanf ("%d %d", &n, &k);
	for (int i=0; i<k; i++) n=sub(n);
	printf ("%d\n", n);
}