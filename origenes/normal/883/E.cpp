#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int flagtar[100];
int flags[2010][100];

bool cmp(string s1, string s2) {
	if (s1.size() != s2.size()) return false;
    bool got[30];
    memset(got,0,sizeof(got));
    for (int i=0; i<s1.size();i++)
    {
        got[s1[i]-'a'] = true;
    }
	for (int i=0; i<s1.size(); i++)
    {
        if (s1[i] == '*' && got[s2[i]-'a'] ) return false;
		if (s1[i] != s2[i] && s1[i]!='*' && s2[i]!='*') return false;
	}
	return true;
}
int  n, m;
string tars, s;
int ans = 0;

int main() {

	cin >> n;

	cin >> tars;

	//cout << tars;
	for (int i=0; i<tars.size(); i++) {
		flagtar[tars[i]-'a'] = 1;
	}


	cin >> m;



	int tot = 0;
	for (int i=1; i<=m; i++) {

		cin >> s;
		if (!cmp(tars, s)) continue;

		tot++;
		for (int j=0; j<s.size(); j++) {
			flags[tot][s[j]-'a'] = 1;
		}
	}



	ans = 0;
	for (int i=0; i<26; i++)
    {
        //printf("i -- %d\n", i);
		if (flagtar[i]) continue;
		int pd =1;
		for (int j=1; j <= tot; j++) {
			if (flags[j][i] == 0) {
				pd = 0;
				break;
			}
		}
		ans += pd;
	}
	//printf("m == %d\n", m);
	cout << ans << endl;

	//puts("OK");
	return 0;
}