
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<bitset>
#include<random>
#include<iostream>
using namespace std;
//#define double long long;
typedef unsigned long long ull;
#define double long double
const double e = 0.00000005;
const double pi = 3.1415926535898;
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
//const long long INF = 100000000000000;
const int Y = 500;
const int INF = 1000000;

bitset<3001>bs;
int arr[3001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    vector<vector<int>>move;
    int n, k;
    cin >> n >> k;
    int cc = 0;
    long long mxm = 0;
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        char tmp = s[i - 1];
        bs[i] = tmp == 'R';
        if (bs[i]) {
            ++cc;
        }
        else {
            mxm += cc;
        }
    }
    while (true) {
        vector<int>tp;
        for (int i = 1; i < n; ++i) {
            if (bs[i] && !bs[i + 1]) {
                tp.push_back(i);
                ++i;
                bs[i] = true;
                bs[i - 1] = false;
            }
        }
        if (tp.size() == 0)break;
        move.push_back(tp);
    }
    if (k < move.size() || k > mxm) {
        cout << -1;
        return 0;
    }
    int i = 0;
    while (move.size() - i < k) {
        cout << "1 " << move[i].back() << "\n";
        move[i].pop_back();
        if (move[i].size() == 0)++i;
        --k;
    }
    for (; i < move.size(); ++i) {
        cout << move[i].size() << " ";
        for (auto x : move[i])cout << x << " ";
        cout << "\n";
    }
    return 0;
}