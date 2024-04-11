#include <bits/stdc++.h>

using namespace std;

long long n , k;
long long c[500010];
long long p[500010];
long long sum[500010];

bool cmp(long long x , long long y){return x > y;}

struct T
{
	long long x;
	long long y;
	T(long long x = 0 , long long y = 0) : x(x) , y(y) {}
};

priority_queue <T> q;

bool operator < (T A , T B)
{
	return A.y < B.y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(long long i = 1; i <= n; i++)
		cin >> c[i];
	sort(c + 1 , c + n + 1 , cmp);
	for(long long i = 1; i <= k + 1; i++)
		q.push(T(i , 0));
	for(long long i = 1; i <= n; i++)
	{
		T t = q.top();
		q.pop();
		q.push(T(t.x , t.y + c[i]));
		p[i] = t.x;
	}
	long long ans = 0;
	for(long long i = 1; i <= n; i++)
	{
		ans += sum[p[i]];
		sum[p[i]] += c[i];
	}
	cout << ans << endl;
	return 0;
}