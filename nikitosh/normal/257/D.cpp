#include<cstdio>
#include<algorithm>

using namespace std;

int N, a[200000], boo[200000], c1, c2, ans;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	boo[N - 1] = 1;
	ans = a[N - 1];
	for (int i = N - 2; i >= 0; i--)
		if (ans > 0)
		{
			boo[i] = 0;
			ans -= a[i];
 		}	
 		else
		{
			boo[i] = 1;
			ans += a[i];
 		}	
 	if (ans < 0)
	{           
	 	for (int i = 0; i < N; i++)
	 		boo[i] = 1 - boo[i];
		ans *= (-1);
	}
	for (int i = 0; i < N; i++)
		if (boo[i] == 0)
			printf("-");
 		else
 			printf("+");
	return 0;
}