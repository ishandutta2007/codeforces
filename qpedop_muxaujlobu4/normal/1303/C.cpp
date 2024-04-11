#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<tuple>
#include<queue>
using namespace std;
const unsigned long long INF = 10000000000000000;
const int Y = 1000000;
const long long m = 1000000007;
bool visited[26];
string h;
set<int>Ed[26];
void dfs(int i) {
    visited[i] = true;
    h.push_back('a' + i);
    for (auto x : Ed[i]) {
        if (!visited[x]) {
            Ed[i].erase(Ed[i].find(x));
            Ed[x].erase(Ed[x].find(i));
            dfs(x);
            break;
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string s;
        cin >> s;
        bool ans = true;
        for (int j = 0; j < 26; ++j) {
            visited[j] = false;
            while (Ed[j].begin() != Ed[j].end())Ed[j].erase(Ed[j].begin());
        }
        h = "";
        int len = s.length();
        for (int j = 1; j < len; ++j) {
            int a = s[j] - 'a';
            int b = s[j - 1] - 'a';
            Ed[a].insert(b);
            Ed[b].insert(a);
        }
        for (int j = 0; j < 26; ++j) {
            if (Ed[j].size() == 1) {
                dfs(j);
            }
        }
        for (int j = 0; j < 26; ++j) {
            if (!visited[j]) {
                if (Ed[j].size() == 0)h.push_back(j + 'a');
                else {
                    ans = false;
                }
            }
            else {
                if (Ed[j].size() != 0)ans = false;
            }
        }
        if (ans) {
            cout << "YES\n";
            cout << h << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */