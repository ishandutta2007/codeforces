#include <cstdio>
#include <algorithm>

int a[7];
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int k; scanf("%d", &k);
		int cnt = 0;
		for(int i = 0; i < 7; i++) scanf("%d", &a[i]), cnt += a[i];
		int lst = k % cnt; 
		if(lst == 0) lst = cnt;
		int sum = (k - lst) / cnt * 7;
		int Min = 8;
		for(int i = 0; i < 7; i++)
		{
			int j = i, o = lst;
			int now = 0;
			while(o > 0)
			{
				if(a[j] == 1) o--;
				j = (j + 1) % 7;
				now++;
			}
			Min = std::min(Min, now);
		}
		printf("%d\n", sum + Min);
	}
	return 0;
}