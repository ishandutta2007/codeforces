#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

int N, boo, k[1005], ans[1005], max1 = -1000000000, sz = 0, ans2[1005];
char s[1005][100], t[1005][100];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//puts("AA");
    scanf("%d\n", &N);
	//puts("AA");
    for (int i = 0; i < N; i++)
    {
    	//puts("AA");
    	boo = 0;
    	scanf("%s%d", s[i], &k[i]);
    	//puts(s[i]);
    	//printf("%d\n", k[i]);
    	for (int j = 0; j < sz; j++)
    		if (strlen(s[i]) == strlen(t[j]))
    		{
    			int boo2 = 0;
    			for (int g = 0; g < (int) strlen(s[i]); g++)
    				if (s[i][g] != t[j][g])
    					boo2 = 1;
    			if (boo2 == 0)
    			{
	    			//puts(s[i]);
    				ans[j] += k[i];
    				boo = 1;
    				break;
    			}
    		}
    	if (boo == 0)
    	{
    		for (int j = 0; j < (int) strlen(s[i]); j++)
	    		t[sz][j] = s[i][j];
    		ans[sz++] = k[i];
    	}
    }
    for (int i = 0; i < sz; i++)
    	max1 = max(max1, ans[i]);
    //printf("%d\n", max1);
    for (int i = 0; i < N; i++)
    {
    	for (int j = 0; j < sz; j++)
    		if (strlen(s[i]) == strlen(t[j]))
    		{
    			int boo2 = 0;
    			for (int g = 0; g < (int) strlen(s[i]); g++)
    				if (s[i][g] != t[j][g])
    					boo2 = 1;
    			if (boo2 == 0)
    			{
	    			//puts(s[i]);
    				ans2[j] += k[i];
    				if (ans2[j] >= max1 && ans[j] == max1)
    				{
    					puts(t[j]);
    					return 0;
    				}
    				break;
    			}
    		}               
    }
 	return 0;
}