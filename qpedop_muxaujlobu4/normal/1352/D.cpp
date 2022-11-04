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
#include<ctime>
#include<random>
using namespace std;
//const unsigned long long INF = 1e17;
const int INF = 2e7;
const int Y = 5000;
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
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int>a;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        int col = 0, s1 = 0, s2 = 0, ls = 0;
        while (!a.empty()) {
            ++col;
            if (col % 2 == 1) {
                int ns = 0;
                while (!a.empty() && ns <= ls) {
                    ns += a.front();
                    a.pop_front();
                }
                s1 += ns;
                ls = ns;
            }
            else {
                int ns = 0;
                while (!a.empty() && ns <= ls) {
                    ns += a.back();
                    a.pop_back();
                }
                s2 += ns;
                ls = ns;
            }
        }

        cout << col << " " << s1 << " " << s2 << endl;
    }
    return 0;
}