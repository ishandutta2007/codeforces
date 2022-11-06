#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s; cin >> s;
	char curr = '-';
	char pre = '-';
	char no = '-';
	int cn = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (curr == s[i]) {
			cn++;
		} else {
			for (int u = 0; u < 26; ++u) {
				if ((u + 'a') != pre && (u + 'a') != curr && (u + 'a') != s[i])
				{
					no = u + 'a';
					break;
				} 
			}
			for (int j = i - 2, c = 1; c < cn; c += 2, j -= 2) s[j] = no; 
			cn = 1;
			pre = curr;
			curr = s[i];
		}
	}
	for (int u = 0; u < 26; ++u) {
		if ((u + 'a') != pre && (u + 'a') != curr)
		{
			no = u + 'a';
			break;
		} 
	}
	for (int j = ((int)s.size()) - 2, c = 1; c < cn; c += 2, j -= 2) s[j] = no; 
	cn = 1;
	cout << s;
}