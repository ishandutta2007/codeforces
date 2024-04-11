#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>
class ST
{
	std::vector<std::vector<T> > table;
	T (*Union)(T, T b);
public:
	ST(std::vector<T>& a,T (*u)(T, T));
	T query(int l ,int r);
};
template<typename T>
ST<T>::ST(std::vector<T>& a, T (*u)(T, T)) {
	Union = u;
	int n = a.size();
	int k = log2(n);
	table.resize(n, std::vector<T> (k+1));
	for (int i = 0; i < n; ++i)
		table[i][0] = a[i];
	for (int j = 1; j <= k; ++j)
		for (int i = 0; i < (n+1-(1<<j)); ++i)
			table[i][j] = Union(table[i][j-1], table[i+(1<<(j-1))][j-1]);
}
template<typename T>
T ST<T>::query(int l, int r)
{
	int m = log2(r-l+1);
	return this->Union(table[l][m], table[r - (1 << m) + 1][m]);
}

int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a%b);
}

bool ok(int len, ST<int>& MIN, ST<int>& GCD, int n)
{
	for (int i = 0; i < n-len+1; ++i)
	{
		if (GCD.query(i, len + i -1) == MIN.query(i, len + i - 1))
			return true;
	}
	return false;
}

void printres(int len, ST<int>& MIN, ST<int>& GCD, int n)
{
	int c = 0;
	std::vector<int> res;
	for (int i = 0; i < n-len+1; ++i)
	{
		if (GCD.query(i, len + i -1) == MIN.query(i, len + i - 1)) {
			c++;
			res.pb(i+1);
		}
	}
	cout << c << " " << len - 1 << "\n";
	for (int i = 0; i < c; ++i)
	{
		cout << res[i] << " ";
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n;
	cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ST<int> MIN(a, ([](int c, int b)->int{return min(c, b);}));
	ST<int> GCD(a, gcd);
	int start = 1;
	int end = n;
	int mid;
	while(start < end) {
		mid = (start + end) >> 1;
		if ((start + end)&1)
			mid ++ ;
		if(ok(mid, MIN, GCD, n))
			start = mid;
		else
			end = mid - 1;
	}
	printres(start, MIN, GCD, n);
}