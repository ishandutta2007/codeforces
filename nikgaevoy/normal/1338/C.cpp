#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ull = unsigned long long;


mt19937 mt(736);


void build_triple(ull n, ull &a, ull &b, ull &c)
{
	ull mult = 1;
	const ull mema[] = {0, 1, 2, 3};
	const ull memb[] = {0, 2, 3, 1};
	const ull memc[] = {0, 3, 1, 2};

	while (n > 0)
	{
		a += mema[n % 4] * mult;
		b += memb[n % 4] * mult;
		c += memc[n % 4] * mult;

		n /= 4;
		mult *= 4;
	}
}


ull build(ull n)
{
	unsigned x = 0;

	while (n >= (1ull << (2 * x)) - 1)
		x++;

	x--;
	ull a = 1ull << (2 * x), b = 2ull << (2 * x), c = 3ull << (2 * x);
	n -= (1ull << (2 * x)) - 1;

	build_triple(n / 3, a, b, c);

	return array{a, b, c}[n % 3];
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		ull n;

		cin >> n;
		n--;

		cout << build(n) << endl;
	}
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int t;

	cin >> t;

	vector<ull> quer(t);

	for (auto &it : quer)
	{
		cin >> it;
		it--;
	}

	vector<unsigned> s;
	unordered_set<unsigned> used;

	auto me = *max_element(quer.begin(), quer.end());

	while (s.size() <= me)
	{
		unsigned a = 1;

		while (used.count(a))
			a++;

		unsigned b = a + 1;

		while (used.count(b) || used.count(a ^ b))
			b++;

		auto c = a ^b;

		assert(c > b);

		s.push_back(a);
		s.push_back(b);
		s.push_back(c);

		used.insert(a);
		used.insert(b);
		used.insert(c);
	}

	for (auto it : quer)
		cout << s.at(it) << endl;
}


void gen(ostream &cout = std::cout)
{
	int t = 1000;

	cout << t << endl;

	for (int i = 1; i <= t; i++)
		cout << t << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	stringstream ss, in1, in2, out1, out2;

	gen(ss);

	in1 << ss.str();
	in2 << ss.str();

	solve(in1, out1);
	stress(in2, out2);

	if (out1.str() != out2.str())
		cout << "bad" << endl;

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}