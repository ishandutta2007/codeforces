#include <bits/stdc++.h>
 
using namespace std;

string solve(const string &a, const string &s)
{
	//cout << "solve " << a.length() << " " << s.length() << endl;
	if (a.empty() && s.empty())
		return "";
	if (s.empty())
		return "-1";
	if (a.empty())
		return s;
	int a_digit = a.back() - '0';
	int s_digit = s.back() - '0';
	int nxt = (s_digit - a_digit + 10) % 10;
	//cout << "nxt " << nxt << endl;
	string res = to_string(nxt + a_digit);
	//cout << "res " << res << endl;
	if (res.size() > s.size() || s.substr(s.length() - res.length()) != res)
		return "-1";
	string ans = solve(a.substr(0, a.length() - 1), s.substr(0, s.length() - res.length()));
	if (ans == "-1")
		return "-1";
	return ans + to_string(nxt);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string a, s;
		cin >> a >> s;
		if (a == s)
			cout << "-1\n";
		else
		{
			cout << stoll(solve(a, s)) << "\n";
		}
	}
	return 0;
}