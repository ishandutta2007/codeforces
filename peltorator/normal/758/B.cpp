#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	string s;
	char c[4] = {'!', '!', '!', '!'};
	cin >> s;
	for (int i = 0; i < s.size(); i++)
        if (s[i] != '!')
            c[i % 4] = s[i];
    vector<int> t(4, 0);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '!')
            t[i % 4]++;
    vector< pair<char, int> > q;
    for (int i = 0; i < 4; i++)
        q.push_back({c[i], t[i]});
    sort(q.begin(), q.end());
    cout << q[2].second << " " << q[0].second << " " << q[3].second << " " << q[1].second;
	return 0;
}