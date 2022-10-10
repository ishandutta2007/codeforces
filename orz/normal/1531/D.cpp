#define _CRT_SECURE_NO_WARNINGS
#define sz(x) (static_cast<int>((x).size()))
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct transform
{
	string new_color;
	int type; // 1 << 0: change from unlock to lock?
	          // 1 << 1: recolor if initially unlocked?
	          // 1 << 2: change from lock to unlock?
	          // 1 << 3: recolor if initially locked?
	transform(const string& new_color = "", const int type = 0) : new_color(new_color), type(type)
	{
	}
	transform combine(const transform& y) const
	{
		return transform(type & 1 << 0 && !(y.type & 1 << 3) || !(y.type & 1 << 1) ? new_color : y.new_color, (type & 1 << 0 && !(y.type & 1 << 2) || !(type & 1 << 0) && y.type & 1 << 0) << 0 |
		                                                                                                      (type & 1 << 1 || type & 1 << 0 && y.type & 1 << 3 || !(type & 1 << 0) && y.type & 1 << 1) << 1 |
		                                                                                                      (type & 1 << 2 && !(y.type & 1 << 0) || !(type & 1 << 2) && y.type & 1 << 2) << 2 |
		                                                                                                      (type & 1 << 3 || type & 1 << 2 && y.type & 1 << 1 || !(type & 1 << 2) && y.type & 1 << 3) << 3);
	}
};
transform by_string_action(const string& action)
{
	if (action == "lock")
		return transform("", 1);
	else if (action == "unlock")
		return transform("", 4);
	else
		return transform(action, 2);
}
struct state
{
	string color;
	bool lock;
	state(const string& color, const bool lock) : color(color), lock(lock)
	{
	}
	state apply(const transform& t) const
	{
		return state(lock ? t.type & 1 << 3 ? t.new_color : color : t.type & 1 << 1 ? t.new_color : color, lock ? !(t.type & 1 << 2) : t.type & 1);
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef ONPC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<vector<transform>> st(1, vector<transform>(n));
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		st.front()[i] = by_string_action(s);
	}
	while (sz(st.back()) > 1)
	{
		st.emplace_back((sz(st.back()) + 1) / 2);
		for (int i = 0; i < sz(st.back()); ++i)
			if (2 * i + 1 < sz(st[sz(st) - 2]))
				st.back()[i] = st[sz(st) - 2][2 * i].combine(st[sz(st) - 2][2 * i + 1]);
			else
				st.back()[i] = st[sz(st) - 2][2 * i];
	}
	const state initial("blue", false);
	cout << initial.apply(st.back().front()).color << '\n';
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int k;
		string new_action;
		cin >> k >> new_action;
		st.front()[--k] = by_string_action(new_action);
		k /= 2;
		for (int i = 1; i < sz(st); ++i, k /= 2)
			if (2 * k + 1 < sz(st[i - 1]))
				st[i][k] = st[i - 1][2 * k].combine(st[i - 1][2 * k + 1]);
			else
				st[i][k] = st[i - 1][2 * k];
		cout << initial.apply(st.back().front()).color << '\n';
	}
}