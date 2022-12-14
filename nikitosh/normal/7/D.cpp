#include<cstdio>
#include<cstring>

using namespace std;

char s[5000005], t[5000005];
int len, d[5000005];
long long ans = 1;
unsigned long long p = 1000000007, ps[5000010], h[5000010], h2[5000010];

int main()
{            	
	gets(s);
	len = strlen(s);
	ps[0] = 1;
	for (int i = 1; i < len + 3; i++)
		ps[i] = ps[i - 1] * p;
	for (int i = 1; i <= len; i++)
		h[i] = h[i - 1] + s[i - 1] * ps[i - 1];
	for (int i = 0; i < len; i++)
		t[i] = s[len - i - 1];
	for (int i = 1; i <= len; i++)
		h2[i] = h2[i - 1] + t[i - 1] * ps[i - 1];
	d[1] = 1;
	for (int i = 2; i <= len; i++)
	{
		if (h[i] * ps[len - i] == h2[len] - h2[len - i])
			d[i] = d[i / 2] + 1;
		else
			d[i] = 0;
		ans += d[i];
		//printf("%d\n", d[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}