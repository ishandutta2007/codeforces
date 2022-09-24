#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int N;
    vector<string>v;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	string s;
	cin >> s;
	v.push_back(s);
    }

    string ans(v[0].size(), '?');
    for (int i=0; i<(int)ans.size(); i++) {
	int cnt[26] = {}, h = 0;
	for (int j=0; j<N; j++) {
	    if (v[j][i] == '?') h++;
	    else cnt[v[j][i]-'a']++;
	}
	int z = 0;
	char c = 'a';
	for (int j=0; j<26; j++) if (cnt[j]) { z++; c = j + 'a'; }
	if (z<2) ans[i] = c;
    }
    cout << ans << endl;
    return 0;
}