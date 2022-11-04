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
int a[8000];
int pref[8001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string ans = "";
        if (n1 == 0) {
            if (n3 == 0) {
                ans = "01";
                --n2;
                while (n2) {
                    --n2;
                    if (ans.back() == '0')ans.push_back('1');
                    else ans.push_back('0');
                }
            }
            else {
                ans = "11";
                --n3;
                while (n3) {
                    --n3;
                    ans.push_back('1');
                }
                while (n2) {
                    --n2;
                    if (ans.back() == '0')ans.push_back('1');
                    else ans.push_back('0');
                }
            }
        }
        else {
            ans = "00";
            --n1;
            while (n1) {
                --n1;
                ans.push_back('0');
            }
            if (n2 != 0) {
                --n2;
                ans.push_back('1');
            }
            while (n3) {
                --n3;
                ans.push_back('1');
            }
            while (n2) {
                --n2;
                if (ans.back() == '0')ans.push_back('1');
                else ans.push_back('0');
            }
        }
        cout << ans << "\n";
    }
    return 0;
}