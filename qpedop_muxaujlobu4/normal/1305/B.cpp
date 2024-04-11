#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
const long long INF = 100000000000000;
const int Y = 200;
const int m = 1000;
int op[2001];
int cl[2001];
bool visited[1000];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int len = s.length();
    vector<int>ViVod;
    int b = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            for (int j = len - 1; j > i; --j) {
                if (visited[j])continue;
                if (s[j] == ')') {
                    ViVod.push_back(i + 1);
                    ViVod.push_back(j + 1);
                    visited[j] = true;
                    break;
                }
            }
        }
    }
    if (ViVod.size() == 0) {
        cout << 0;
    }
    else {
        cout << 1 << "\n" << ViVod.size() << "\n";
        sort(ViVod.begin(), ViVod.end());
        for (auto x : ViVod)cout << x << " ";
    }
    return 0;
}