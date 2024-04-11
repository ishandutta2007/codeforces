#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXPRIME = 2e6;

bool is_prime[MAXPRIME];
set<long long > primes;
long long arr[MAXN];
int N;

void sieve(void)
{
	fill(is_prime + 2, is_prime + MAXPRIME, true);
	for (int i(2); i < MAXPRIME; i++)
		if (is_prime[i])
		{
			primes.insert(i);
			for (int j(2*i); j < MAXPRIME; j += i)
				is_prime[j] = false;
		}
}

long long get_smallest_prime(long long n)
{
	for (int i(n+1);; ++i)
	{
		int c = i;
		auto it = primes.begin();
		while (it != primes.end() and *it <= c and c != 1)
		{
			while (c % *it==0)
				c /= *it;
			it++;
		}
		if (c == 1) {
			c = i;
			it = primes.begin();
			while (it != primes.end() and *it <= c and c != 1)
			{
				if (c % *it == 0)
				{
					while (c % *it == 0)
						c /= *it;
					it = primes.erase(it);
				}else
					it++;
			}
			return i;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	sieve();
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i(0); i < N; ++i)
	{
		auto it = primes.begin();
		long long cur(arr[i]);
		list<long long> to_remove;
		while (cur != 1 and it != primes.end() and cur >= *it)
		{
			if (cur % *it == 0)
			{
				while (cur % *it == 0)
					cur /= *it;
				to_remove.push_back(*it);
			}
			++it;
		}
		if (cur == 1) {
			for (auto t : to_remove)
				primes.erase(t);
			continue;
		}
		long long new_prime = get_smallest_prime(arr[i]);
		arr[i] = new_prime;
		it = primes.begin();
		for (int j(i+1); j < N; ++j)
			arr[j] = *(it++);
		break;
	}
	for (int i = 0; i < N; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}