#include <bits/stdc++.h>

#define N 500005

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int a, b, c, d;

void Main()
{
	scanf("%d%d", &a, &b);
	scanf("%d%d", &c, &d);
	while (a < c && b > d) a *= 10, --b;
	while (c < a && d > b) c *= 10, --d;
	if (b > d) puts(">");
	else if (b < d) puts("<");
	else if (a == c) puts("=");
	else if (a > c)  puts(">");
	else if (a < c)  puts("<");
	
}

int main()
{
	int T; scanf("%d", &T);
	for (;T--;) Main(); 
}