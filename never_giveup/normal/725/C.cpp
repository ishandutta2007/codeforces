#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

char q[2][26];

int p[26], pos;

vector<pair<int, int> > e;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gallo.in");
    //ofstream cout("gallo.out");
    #endif
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++)
        p[i] = -1;
    for (int i = 0; i < s.length(); i++){
        if (p[s[i] - 'A'] == -1)
            p[s[i] - 'A'] = i;
        else
        if (s[i] == s[i - 1]){
            cout << "Impossible";
            return 0;
        }
        else
            pos = i;
    }
    int n = 13;
    int len = pos - p[s[pos] - 'A'] - 1;
    int num = s[pos] - 'A';
    int now = 0;
    q[1][n - len / 2 - 1] = s[pos];
    for (int i = n - len / 2 - 2; i >= 0; i--)
        e.push_back(make_pair(1, i));
    for (int i = 0; i < n - len / 2 - 1; i++)
        e.push_back(make_pair(0, i));
    for (int i = 0; i < min((int)e.size(), 26 - pos); i++)
        q[e[i].first][e[i].second] = s[pos + i + 1];
    for (int i = 26 - pos; i < e.size(); i++)
        q[e[i].first][e[i].second] = s[now], now++;
    if (len % 2 == 0)
        if (p[num] > 0)
            q[0][n - len / 2 - 1] = s[now], now++;
        else
            q[0][n - len / 2 - 1] = s[26];
    else
        q[0][n - len / 2 - 1] = s[pos - 1];
    now++;
    for (int i = n - len / 2; i < n; i++)
        q[1][i] = s[now], now++;
    for (int i = n - 1; i >= n - len / 2; i--)
        q[0][i] = s[now], now++;
    for (int i = 0; i < n; i++)
        cout << q[0][i];
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << q[1][i];
    cout << endl;
}