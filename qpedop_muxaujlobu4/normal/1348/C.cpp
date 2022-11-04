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
const unsigned long long INF = 1e17;
const int INFi = 2e7;
const int Y = 200100;
const long long m = 1000000007;
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
struct Cyst {
    long long a;
    long long b;
    Cyst(long long A = 0, long long B = 0) {
        a = A;
        b = B;
    }
};
//bool dp[501][501][501];
//Cyst arr[501];
long long arr[26];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < 26; ++i)arr[i] = 0;
        for (auto x : s)arr[x - 'a']++;
        int st = 0;
        string ans = "";
        while (arr[st] == 0)++st;
        if (arr[st] >= k) {
            arr[st] -= k;
            int kol = 0;
            for (int i = st; i < 26; ++i)kol += arr[i] != 0;
            if (kol == 0) {
                ans.push_back(st + 'a');
            }
            else {
                if (kol == 1) {
                    int fd;
                    ans.push_back(st + 'a');
                    for (int i = st; i < 26; ++i)if (arr[i] != 0)fd = i;
                    n -= k;
                    n = (n + k - 1) / k;
                    for (int i = 0; i < n; ++i)ans.push_back(fd + 'a');
                }
                else {
                    ans.push_back(st + 'a');
                    for (int i = st; i < 26; ++i) {
                        for (int j = 0; j < arr[i]; ++j)ans.push_back('a' + i);
                    }
                }
            }
        }
        else {
            sort(s.begin(), s.end());
            ans.push_back(s[k - 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}