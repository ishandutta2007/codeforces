#include<bits/stdc++.h>
using namespace std;
const int N=2e3;

int read() {
	int x = 0;
	char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) {
		if (ch == '-') {
			f ^= 1;
		}
	}
	for (; isdigit(ch); ch = getchar()) {
		x = (x << 1) + (x << 3) + (ch ^ '0');
	}
	return f ? x : -x;
}
void print(int x, char ch = '\n') {
	if (x == 0) {
		putchar('0');
		putchar(ch);
		return;
	}
	int cnt = 0, num[25];
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	for (; x; x /= 10) {
		num[++cnt] = x % 10;
	}
	while (cnt) {
		putchar(num[cnt] ^ '0');
		--cnt;
	}
	putchar(ch);
}
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int a[N];

int main()
{
	int n=read(),g=0;
	for (int i=1;i<=n;i++) g=gcd(g,a[i]=read());
	if (g==a[1])
	{
		print(2*n);
		for (int i=1;i<=n;i++)
		{
			print(a[1],' ');
			print(a[i],' ');
		}
	}
	else puts("-1");

	return 0;
}