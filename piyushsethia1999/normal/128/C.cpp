#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

std::vector<ll> res(10001);
std::vector<ll> temp(10001);
ll mod = 1e9 + 7;

void preprocess(int k)
{
	temp[0] = 1;
	res[0] = 0;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = k; j >= 1; --j) {
			temp[j] = temp[j] + temp[j-1];
			if(temp[j] > mod)
				temp[j] -= mod;
		}
		res[i] = temp[k];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	preprocess(2 * k);
	cout << (res[n-1] * res[m-1]) % mod;
}