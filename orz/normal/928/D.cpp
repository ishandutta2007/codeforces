#define _CRT_SECURE_NO_WARNINGS
#define sz(x) ((int)(x.size()))
#define UM map
#define US set
#define X first
#define Y second
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool bookva(const char& c)
{
	return ((c >= 'a') && (c <= 'z'));
}

const int& M1 = 1000000007, P1 = 85782,
M2 = 1000000009, P2 = 67891;

int umn(const ll& a, const ll& b, const ll& m)
{
	return (a * b) % m;
}

int slo(const int& a, const int& b, const int& m)
{
	int c = a + b;
	return (c >= m ? c - m : c);
}

void add_visit(US<pii>& vis, const string& word)
{
	pii h(0, 0);
	int i = 0, n = sz(word), s1 = 1, s2 = 1;
	while (i < n)
	{
		h = pii(slo(h.X, umn(s1, word[i], M2), M1), slo(h.Y, umn(s2, word[i], M2), M2));
		s1 = umn(s1, P1, M1);
		s2 = umn(s2, P2, M2);
		vis.insert(h);
		++i;
	}
}

int dictionarify(vector<string>& words, UM<pii, int>& dict, US<pii>& vis, const string& word)
{
	pii h(0, 0);
	int i = 0, n = sz(word), s1 = 1, s2 = 1;
	while ((i < n) && ((vis.find(h) != vis.end()) && (dict.find(h) == dict.end())))
	{
		h = pii(slo(h.X, umn(s1, word[i], M2), M1), slo(h.Y, umn(s2, word[i], M2), M2));
		s1 = umn(s1, P1, M1);
		s2 = umn(s2, P2, M2);
		++i;
	}
	auto aut = dict.find(h);
	if (aut != dict.end())
	{
		int numb_u = aut->Y;
		int m = sz(words[numb_u]);
		int k = min(m, n);
		if (words[numb_u] == word)
			return min(n, i + 1);
		int numb_word = sz(words);
		words.push_back(word);
		dict.erase(aut);
		int j = i;
		while ((i < k) && (words[numb_u][i] == word[i]))
		{
			h = pii(slo(h.X, umn(s1, word[i], M2), M1), slo(h.Y, umn(s2, word[i], M2), M2));
			s1 = umn(s1, P1, M1);
			s2 = umn(s2, P2, M2);
			++i;
		}
		if (i == n)
		{
			h = pii(slo(h.X, umn(s1, words[numb_u][i], M2), M1), slo(h.Y, umn(s2, words[numb_u][i], M2), M2));
			dict.insert({ h, numb_u });
			return n;
		}
		else if (i == m)
		{
			h = pii(slo(h.X, umn(s1, word[i], M2), M1), slo(h.Y, umn(s2, word[i], M2), M2));
			dict.insert({ h, numb_word });
			add_visit(vis, word);
			int first_word = min(m, j + 1);
			return first_word + (n - m);
		}
		else
		{
			pii h1 = pii(slo(h.X, umn(s1, words[numb_u][i], M2), M1), slo(h.Y, umn(s2, words[numb_u][i], M2), M2));
			dict.insert({ h1, numb_u });
			h = pii(slo(h.X, umn(s1, word[i], M2), M1), slo(h.Y, umn(s2, word[i], M2), M2));
			dict.insert({ h, numb_word });
			add_visit(vis, word);
			return n;
		}
	}
	if (vis.find(h) == vis.end())
	{
		int numb_word = sz(words);
		words.push_back(word);
		dict.insert({ h, numb_word });
		add_visit(vis, word);
		return n;
	}
	return n;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	int ans = 0;
	UM<pii, int> dict;
	vector<string> words;
	US<pii> vis;
	vis.insert({ 0, 0 });
	while (getline(cin, s))
	{
		++ans;
		int n = sz(s);
		for (int i = 0; i < n; ++i)
		if (bookva(s[i]))
		{
			string word(1, s[i]);
			int j = i;
			while (bookva(s[++j]))
				word.push_back(s[j]);
			ans += dictionarify(words, dict, vis, word);
			i = j - 1;
		}
		else
			++ans;
	}
	cout << ans << '\n';
	return 0;
}