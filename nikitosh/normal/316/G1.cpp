#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>

using namespace std;

char s[2000], t[15][2000];
int len, N, l[15], r[15], lens[15], cur_len, ans = 0, boo, cnt = 0;
unsigned long cur_h, hash, ps[2000], p = 1000000007, h[2000], h2[15][2000];
map <string, int> used;
string t2;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	gets(s);
	len = strlen(s);
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s%d%d\n", t[i], &l[i], &r[i]);
		lens[i] = strlen(t[i]);
		//puts(t[i]);
	}
	ps[0] = 1;
	for (int i = 1; i < 1000; i++)
		ps[i] = ps[i - 1] * p;
	h[0] = s[0] - 'a' + 1;
	for (int i = 1; i < len; i++)
	{
		h[i] = ps[i] * (s[i] - 'a' + 1) + h[i - 1];
	}
	for (int i = 0; i < N; i++)
	{
		h2[i][0] = t[i][0] - 'a' + 1;
		for (int j = 1; j < lens[i]; j++)
		{
			h2[i][j] = ps[j] * (t[i][j] - 'a' + 1) + h2[i][j - 1];
		}	
	}
	//cout << h2[0][1] << endl;
	//cout << h2[1][1] << endl;
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			boo = 0;
			if (i != 0)
				hash = h[j] - h[i - 1];
			else
				hash = h[j];
			cur_len = j - i + 1;
			//cout << hash << endl;
			for (int g = 0; g < N; g++)
			{
				ans = 0;
				for (int k = 0; k + cur_len - 1 < lens[g]; k++)
				{
					cur_h = h2[g][k + cur_len - 1];
					if (k != 0) 
						cur_h -= h2[g][k - 1];
					if (cur_h * ps[i] == hash * ps[k])
					{
					    //printf("k = %d\n", k);
						ans++;
					}
				}
				if (ans < l[g] || ans > r[g])
					boo = 1;
				//printf("i = %d j = %d ans = %d\n", i, j, ans);
			}
			if (boo == 0)
			{
				t2 = "";
				for (int g = i; g <= j; g++)
					t2 += s[g];
				if (used[t2] == 0)
				{
					used[t2] = 1;
					cnt++;
				}	
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}