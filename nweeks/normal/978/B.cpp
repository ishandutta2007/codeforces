#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	int n;
	string s, t = "";
	cin >> n >> s;

	int ans(0);
	for (auto c : s)
	{
		if (c != 'x' or t.size() < 2 or t.back() != 'x' or t[t.size()-2] != 'x')
			t += c;
		else
			++ans;
	}
	cout <<  ans << endl;
}