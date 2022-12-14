#include<cstdio>

char a[100];
int ans1, ans2, boo1, boo2;

int main()
{
	scanf("%c%c%c\n%c%c%c\n%c%c%c", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);
	for (int i = 1; i < 10; i++)
	{
		if (a[i] == 'X')
			ans1++;
		if (a[i] == '0')
			ans2++;
	}
	for (int i = 0; i < 3; i++)
    	if (a[3 * i + 1] == a[3 * i + 2] && a[3 * i + 1] == a[3 * i + 3])
    	{
    		if (a[3 * i + 1] == 'X')
    			boo1 = 1;
    		if (a[3 * i + 1] == '0')
    			boo2 = 1;
    	}
    for (int i = 1; i < 4; i++)
    	if (a[i] == a[i + 3] && a[i] == a[i + 6])
    	{
    		if (a[i] == 'X')
    			boo1 = 1;
    		if (a[i] == '0')
	   			boo2 = 1;
    	}
   	if (a[1] == a[5] && a[1] == a[9])
   	{
   		if (a[1] == 'X')
  			boo1 = 1;
   		if (a[1] == '0')
   			boo2 = 1;
   	}
   	if (a[3] == a[5] && a[3] == a[7])
   	{
   		if (a[3] == 'X')
  			boo1 = 1;
   		if (a[3] == '0')
   			boo2 = 1;
   	}
   	if (ans2 > ans1 || ans1 > ans2 + 1 || (boo1 * boo2 == 1) || (ans1 == ans2 && boo1 == 1) || (ans1 > ans2 && boo2 == 1))
	{
    	puts("illegal");
    	return 0;
    }
    for (int i = 0; i < 3; i++)
    	if (a[3 * i + 1] == a[3 * i + 2] && a[3 * i + 1] == a[3 * i + 3])
    	{
    		if (a[3 * i + 1] == 'X')
    		{
    			puts("the first player won");
    			return 0;
    		}
    		if (a[3 * i + 1] == '0')
    		{
    			puts("the second player won");
    			return 0;
    		}
    	}
    for (int i = 1; i < 4; i++)
    	if (a[i] == a[i + 3] && a[i] == a[i + 6])
    	{
    		if (a[i] == 'X')
    		{
    			puts("the first player won");
    			return 0;
    		}
    		if (a[i] == '0')
    		{
    			puts("the second player won");
    			return 0;
    		}
    	}
   	if (a[1] == a[5] && a[1] == a[9])
   	{
   		if (a[1] == 'X')
   		{
   			puts("the first player won");
   			return 0;
   		}
   		if (a[1] == '0')
   		{
   			puts("the second player won");
   			return 0;
   		}
   	}
   	if (a[3] == a[5] && a[3] == a[7])
   	{
   		if (a[3] == 'X')
   		{
   			puts("the first player won");
   			return 0;
   		}
   		if (a[3] == '0')
   		{
   			puts("the second player won");
   			return 0;
   		}
   	}
   	if (ans1 + ans2 == 9)
   	{
   		puts("draw");
   		return 0;
   	}
   	if (ans1 == ans2)
   		puts("first");
   	else
   		puts("second");

	return 0;
}