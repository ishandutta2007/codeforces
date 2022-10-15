#include <bits/stdc++.h>
#define mp make_pair
 
using namespace std;
struct pairvar
{
	int a;
	int b;
	int c;
	int d;
 
};
bool isEven(long long x){
	return x % 2 == 0;
}
bool isPrime(long long x){
	if (x == 1){
		return false;
	}
 
	long long a = (long long)x;
	for (int i = 2; i <= (long long)sqrt((double)a); i++)
	{
		if (a%i == 0){
			return false;
		}
	}
	return true;
}
long long gcd(long long a, long long b){
	if (b == 0){
		return a;
	}
	return gcd(b, a%b);
}
long long factorial(long long x){
	long long sum = 1;
	for (long long i = 1; i <= x; i++)
	{
		sum *= i;
	}
	return sum;
}
int toint(string s){
	int x = 0;
	int k = (int)pow(10, (double)s.length() - 1);
	for (int i = 0; i < (int)s.length(); i++)
	{
		x += (s[i] - '0')*k;
		k /= 10;
	}
	return x;
}
string tostr(int x){
	if (x == 0){
		return "0";
	}
	string s = "";
	bool f = x < 0;
	x = abs(x);
	while (x != 0)
	{
		s += (x % 10) + '0';
		x /= 10;
	}
	string t = "";
	if (f){
		t = "-";
	}
	for (int i = s.length() - 1; i >= 0; i--)
	{
		t += s[i];
	}
	return t;
}
long long lcm(long long a, long long b){
	return (a*b) / gcd(a, b);
}
bool cmp(const pair<double, double> &a, const pair<double, double> &b) {
 
	if (a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}
 
 
const long long MOD = 1000000007;
 
long long bpow(long long x, long long v) {
	if (v == 0)
		return 1 % MOD;
 
	if (v % 2 == 1)
		return (x * bpow(x, v - 1)) % MOD;
 
	long long r = bpow(x, v / 2);
 
	return (r * r) % MOD;
}
int pred[1005];
int n = 0;
set<pair<int, int>>kek;
int mark[1005];
int cnt[1005][1005];
bool f = false;
void dfs(int v){
	mark[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[v][i] == 1 && mark[i] != 1){
			pred[i] = v;
			dfs(i);
		}
		else if (!f && cnt[v][i] == 1 && mark[i] == 1 && i != pred[v]){
			kek.insert(mp(min(i, v), max(i, v)));
		}
	}
}
int main()
{
	cin >> n;
	mark[n + 1];
	cnt[n + 1][n + 1];
	pred[n + 1];
	for (int i = 1; i <= n; i++)
	{
		pred[i] = 0;
		for (int e = 1; e <= n; e++)
		{
			cnt[i][e] = 0;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		cin >> v >> u;
		cnt[u][v] = 1;
		cnt[v][u] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		mark[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 0){
			dfs(i);
		}
	}
	f = true;
	vector<pair<int, int>>lol;
	for (auto j : kek){
		int v = j.first;
		int u = j.second;
		cnt[v][u] = 0;
		cnt[u][v] = 0;
		lol.push_back(mp(u, v));
	}
	cout << lol.size() << endl;
	for (int i = 1; i <= n; i++)
	{
		mark[i] = 0;
	}
	vector<int>comp;
	for (int i = 1; i <= n; i++)
	{
		if (!mark[i]){
			comp.push_back(i);
			dfs(i);
		}
	}
	for (int i = 0; i < comp.size() - 1; i++)
	{
		cout << lol[i].first << " " << lol[i].second << " " << comp[i] << " " << comp[i + 1] << endl;
	}
	return 0;
}