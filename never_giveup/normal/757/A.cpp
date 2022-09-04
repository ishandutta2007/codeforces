/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int a[27];

int main(){
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            a[s[i] - 'a']++;
        else
        if (s[i] == 'B')
            a[26]++;
    int answer = inf;
    answer = min(answer, a[26]);
    answer = min(answer, a['u' - 'a'] / 2);
    answer = min(answer, a['l' - 'a']);
    answer = min(answer, a['b' - 'a']);
    answer = min(answer, a[0] / 2);
    answer = min(answer, a['s' - 'a']);
    answer = min(answer, a['r' - 'a']);
    cout << answer;
}