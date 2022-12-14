#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int n, ten[10], len, boo, l, sz, t;
char s[100];
vector <int> ans;

int main()
{
	ten[0] = 1;
	for (int i = 1; i < 8; i++)
		ten[i] = ten[i - 1] * 10;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		len = strlen(s);
		if (s[0] == 'R' && (s[1] >= '0' && s[1] <= '9'))
		{
			boo = 0;
			for (int j = 0; j < len; j++)
				if (s[j] == 'C')
				{
					boo = 1;
					l = j;
				}
			if (boo == 0)
			{
				for (int j = 0; j < len; j++)
					printf("%c", s[j]);
				printf("C%d", 'R' - 'A' + 1);
				puts("");	
			}
			else
			{
				ans.clear();
				sz = 0;
				for (int j = l + 1; j < len; j++)
					sz += (s[j] - '0') * ten[len - j - 1];
				while(sz > 0)
				{
					if (sz % 26 == 0)
					{
						ans.push_back(26);
						sz -= 26;
					}
					else
						ans.push_back(sz % 26);
					sz /= 26;
				}
				reverse(ans.begin(), ans.end());
				for (int j = 0; j < (int) ans.size(); j++)
					printf("%c", 'A' + ans[j] - 1);
				for (int j = 1; j < l; j++)
					printf("%c", s[j]);
				puts("");
			}
        }
        else
        {
        	sz = 0;
        	for (int j = 0; j < len; j++)
        		if (s[j] >= '0' && s[j] <= '9')
        		{
					l = j;
					break;        			
        		}
        	printf("R");
        	for (int j = l; j < len; j++)
        		printf("%c", s[j]);
        	printf("C");
        	t = 1;
        	for (int j = l - 1; j >= 0; j--)
        	{
        		sz += (s[j] - 'A' + 1) * t;
        		t *= 26;
        	}
        	printf("%d\n", sz);
        }
	}
}