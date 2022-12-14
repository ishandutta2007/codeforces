#include<cstdio>
#include<cstring>

using namespace std;

char s[1000005], t[1000005];
int a[1000005], b[1000005], len, len2, p, q, boo, c1[3], c2[3];

int main()
{
	gets(s);
	gets(t);
	len = strlen(s);
	len2 = strlen(t);
	if (len != len2)
	{
	 	printf("NO\n");
	 	return 0;
	}
	for (int i = 0; i < len; i++)
	{
		a[i] = s[i] - '0';
		c1[a[i]]++;
		b[i] = t[i] - '0';
		c2[b[i]]++;
	}
	if ((c1[0] == len && c2[0] != len) || (c1[0] != len && c2[0] == len))
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}