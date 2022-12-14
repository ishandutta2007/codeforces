#include<cstdio>
#include<cstring>

using namespace std;

char s[1000];
int ans = 0, ANS = 0, len, l;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (gets(s))
	{
		//puts(s);
		len = strlen(s);
		if (s[0] == '+')
		{
			ans++;
			continue;
		}
		if (s[0] == '-')
		{
			ans--;
			continue;
		}
		for (int i = 0; i < len; i++)
			if (s[i] == ':')
				l = i;
		ANS += ans * (len - l - 1);
		//printf("%d\n", ANS);
	}
	printf("%d\n", ANS);
	return 0;
}