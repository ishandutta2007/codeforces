#define sz(x) ((int)(x).size())
#include<deque>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for (int I = 0; I < t; I++)
	{
		getline(cin, s);
		deque<char> d(s.begin(), s.end());
		for (int i = sz(d) - 1; i >= 0; i--)
			if (d.front() - 'a' == i)
				d.pop_front();
			else if (d.back() - 'a' == i)
				d.pop_back();
			else
				break;

		cout << (d.empty() ? "yes\n" : "no\n");
	}
}