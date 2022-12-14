#include<cstdio>
#include<cstring>

using namespace std;

char s[100005], t[100005], r[100005];
int len1, len2, a1[50], a2[50], ans = 0, dop[50], c;

int main()
{                                    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	gets(s);
	gets(t);
	len1 = strlen(s);
	len2 = strlen(t);
	for (int i = 0; i < len1; i++)
		r[i] = ' ';
	for (int i = 0; i < len1; i++)
		a1[s[i] - 'A']++;
	for (int i = 0; i < len2; i++)
		a2[t[i] - 'A']++;
	for (int i = 0; i < 30; i++)
		dop[i] = a2[i] - a1[i];
	for (int i = 0; i < 30; i++)
	{
		if (dop[i] <= 0)
		{
			c = 0;
			for (int j = 0; j < len1; j++)
			{
				if (c == a2[i])
					break;
				if (s[j] == 'A' + i && r[j] == ' ')
				{
					r[j] = s[j];
					c++;
				}
			}
			//dop[i] = 0;
		}
		else
		{
			//printf("%c\n", 'A' + i);
			c = 0;
			for (int j = 0; j < len1; j++)
			{
				if (s[j] == 'A' + i && r[j] == ' ')
				{
					c++;
					r[j] = s[j];
					dop[s[j] - 'A']++;
					//printf("%c\n", i + 'A');
				}
			} 
			for (int j = 0; j < len1; j++)
			{ 	
			 	if (c == a2[i])
					break;
				
			 	if (s[j] != 'A' + i)
				{
					if (dop[s[j] - 'A'] < 0 && r[j] == ' ')
					{
						//printf("j = %d %c\n", j, i + 'A');
						ans++;
						c++;              
						dop[s[j] - 'A']++;
						s[j] = 'A' + i;
						r[j] = 'A' + i;          
					}
				}
			}
			//printf("dop %d\n", dop['P' - 'A']);               
		}
	}
	//puts(r);
	//for (int i = 0; i < 30; i++)
	//	printf("%d ", dop[i]);
	/*for (int i = 0; i < 30; i++)
	{
		ans += dop[i];
		while (dop[i] != 0)
		{
			for (int j = 0; j < len1; j++)
			{
				if (dop[i] == 0)
					break;
				if (r[j] == ' ')
				{
					r[j] = i + 'A';
					dop[i]--;
				}
			}
			//puts(r);
		}
	} */
	printf("%d\n", ans);
	puts(r);                                        
	return 0;
}