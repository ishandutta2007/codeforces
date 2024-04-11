#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();

mt19937_64 gen(seed);

const int MAXN = 2e5;

ll arr[MAXN];

int n;
ll ans;

ll get_gcd(void)
{
	ll g(arr[0]);
	for (int i(1); i < n; ++i)
		g = gcd(arr[i], g);
	return g;
}

ll get_to_even(void)
{
	int cnt(0);
	for (int i(0); i < n; ++i)
		cnt += arr[i]%2;
	return cnt;
}

void solve(ll starting_number)
{
	while (starting_number % 2==0 and starting_number > 1)
		starting_number /= 2;
	if (starting_number <= 1)
		return ;
	for (ll i(3); i * i <= starting_number ; ++i)
	{
		if (starting_number % i)
			continue;
		while (starting_number % i == 0)
			starting_number /= i;
		ll cnt(0);
		for (int j(0); j < n and cnt < ans; ++j)
		{
			if (arr[j] < i)
				cnt += i - arr[j]%i;
			else
				cnt += min(arr[j]%i, i - arr[j]%i);
		}
		ans = min(ans, cnt);
	}
	if (starting_number > 1)
	{
		ll cnt(0);
		for (int j(0); j < n and cnt < ans; ++j)
		{
			if (arr[j] < starting_number)
				cnt += starting_number - arr[j]%starting_number;
			else
				cnt += min(arr[j]%starting_number, starting_number - arr[j]%starting_number);
		}
		ans = min(ans, cnt);
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i(0); i < n; ++i)
		cin >> arr[i];

	if (get_gcd() > 1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	ans = get_to_even();
	shuffle(arr, arr + n, gen);

	for (int i(0); i < 30; ++i)
		for (int j(-1); j <= 1; ++j)
				solve(arr[i] + j);

	cout << ans << endl;
}