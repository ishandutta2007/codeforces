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
//#define double long long;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
const double e = 0.0000005;
const double pi = 3.14159265359;
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
const int Y = 100000;
long long arr[Y + 1];
bool visited[Y + 1];
int ans[Y + 1];
int Col[Y + 1];
vector<pair<int,int>>Ed[Y + 1];
pair<int, int>SP[Y + 1];
unsigned long long ct[63];
int main()
{
    cout.precision(10);
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    unsigned long long u, v;
    cin >> u >> v;
    if (u > v) {
        cout << -1;
        return 0;
    }
    if (u == v) {
        if (v != 0)
            cout << 1 << "\n" << v;
        else cout << 0;
        return 0;
    }
    /*if (u == 0) {
        if (v % 2 == 0) {
            cout << 2 << "\n";
            cout << v / 2 << " " << v / 2;
        }
        else cout << -1;
        return 0;
    }*/
    for (long long i = 62; i >= 0; --i) {
        ct[i] = v & ((unsigned long long)1 << i);
        if (ct[i])ct[i] = 1;
    }
    for (long long i = 62; i >= 0; --i) {
        if (ct[i] % 2 == 0) {
            if (u & ((unsigned long long)1 << i)) {
                if (ct[i] == 0 || i == 0) {
                    bool fal = false;
                    long long j = i + 1;
                    for (j; j <= 62; ++j) {
                        if (ct[j] >= 2) {
                            ct[j] -= 2;
                            fal = true;
                            break;
                        }
                        else {
                            ct[j] += 2;
                        }
                    }
                    if (fal && i) {
                        ct[i] += 3;
                        ct[i - 1] += 2;
                        continue;
                    }
                    cout << -1;
                    return 0;
                }
                else {
                     --ct[i];
                      ct[i - 1] += 2;
                }
            }
        }
        else {
            if ((u & (((unsigned long long)1 << i)))==0 ) {
                if (i) {
                    --ct[i];
                     ct[i - 1] += 2;
                }
                else {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    unsigned long long col = 0;
    for (int i = 62; i >= 0; --i) col = max(col, ct[i]);
    cout << col << "\n";
    vector<  unsigned long long>ans(col);
    for (long long i = 62; i >= 0; --i) {
        for (long long j = 0; j < ct[i]; ++j) {
            ans[j] += ((unsigned long long)1 << i);
        }
    }
    for (unsigned long long x : ans)cout << x << " ";
    return 0;
}
/* Thu Mar 05 2020 12:52:50 GMT+0300 (MSK) */
 
/* Fri Mar 06 2020 21:40:12 GMT+0300 (MSK) */
 
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);