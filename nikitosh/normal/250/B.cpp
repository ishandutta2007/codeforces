#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int n, len, size1, l;
char s[2000];
vector <int> c;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		c.clear();
		size1 = 0;
		if (s[0] != ':')
		{
			c.push_back(-1);
		}
		len = strlen(s);
		if (len == 2)
		{
			printf("0000:0000:0000:0000:0000:0000:0000:0000\n");
			continue;
		}
		for (int j = 0; j < len; j++)
		{
			if (s[j] == ':')
				c.push_back(j);
		}
		if (s[len - 1] != ':')
		{
			c.push_back(len);
		}
		size1 += c.size() - 2;
		//printf("%d\n", size1);
		for (int j = 1; j < (int) c.size(); j++)
		{
			if (c[j] != c[j - 1] + 1)
			{
				//printf("aaa %d\n", i);
				l = c[j] - c[j - 1] - 1;
				for (int g = 0; g < 4 - l; g++)
					printf("0");
				for (int g = c[j - 1] + 1; g < c[j]; g++)
					printf("%c", s[g]);
				if (c[j] != len)
					printf("%c", s[c[j]]);
			}
			else
			{
				if (c[j] != len - 1 && c[j] != 0)
				{
					//printf("OOO\n");
					for (int g = 0; g < 7 - size1 + 1; g++)
						printf("0000:");	
				}
				else
				{
					for (int g = 0; g < 7 - size1; g++)
						printf("0000:");	
					printf("0000");
				}
			
			}
		}
		puts("");
	}
	return 0;
}