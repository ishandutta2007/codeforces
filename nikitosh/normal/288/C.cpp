#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N, b[1000005], used[1000005], l;
long long sz;
vector <int> v;

int inv (int a)
{
	int ans = 0;
	while (a > 0)
	{
		v.push_back(1 - (a % 2));
		a /= 2;
	}	
	//reverse(v.begin(), v.end());
	for (int i = 0; i < (int) v.size(); i++)
		ans += v[i] * (1 << i);
	v.clear();
	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = N; i >= 0; i--)
	{
		if (used[i] == 1)
			continue;
		l = inv(i);
		used[i] = 1;
		used[l] = 1;
		b[i] = l;
		b[l] = i;
		sz += 2 * (i ^ l);
	}
	printf("%I64d\n", sz);
	for (int i = 0; i <= N; i++)
		printf("%d ", b[i]);
	return 0;
}