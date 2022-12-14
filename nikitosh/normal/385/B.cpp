#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, ans = 0, sz;
char s[10005];
vector <int> v;

int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n - 3; i++)
	{
		if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r')
			v.push_back(i);
	}
	sz = (int) v.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sz; j++)
			if (v[j] >= i)
			{
				ans += n - v[j] - 3;
				break;
			}
	}
	printf("%d\n", ans);
}