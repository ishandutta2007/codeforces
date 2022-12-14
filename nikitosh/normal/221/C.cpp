#include<cstdio>
#include<algorithm>

using namespace std;

int N, a[200000], b[200000], ans;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + N);
	for (int i = 0; i < N; i++)
		if (a[i] != b[i])
			ans++;
 	if (ans <= 2)
 		printf("YES\n");
 	else 	
 		printf("NO\n");
	return 0;
}