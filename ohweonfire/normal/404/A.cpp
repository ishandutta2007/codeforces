#include <cstdio>
using namespace std;
int n;
char s[310][310];
bool ans = true;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i == j || i == n - 1 - j) && s[i][j] != s[0][0] || (i != j && i != n - 1 - j) && s[i][j] != s[0][1])
				ans = false;
	if (s[0][0] == s[0][1])
		ans = false;
	if (ans)
		printf("YES");
	else
		printf("NO");
	return 0;
}