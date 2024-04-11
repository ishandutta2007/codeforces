#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
const int MAXN = 305;


int n, inp[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    vector <int> p;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vector <int> newn;
        if ((num + 8) / 9 < szof(p) || ((num + 8) / 9 == szof(p) && num % 9 <= p[0])) {            
            bool flag = true;
            int pref = 0;
            for (int j = 0; j < szof(p); ++j) {
                pref += p[j];
                if (p[j] != 9 && pref < num) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                vector <int> revsum;
                revsum.resize(szof(p) + 1);
                revsum[szof(p)] = 1e9;
                for (int j = szof(p) - 1; j >= 0; --j) {
                    if (p[j] != 9) {
                        revsum[j] = p[j] + 1;
                    } else {
                        revsum[j] = revsum[j + 1] + 9;
                    }
                }
                bool alr = false;
                for (int j = 0; j < szof(p); ++j) {
                    if (!alr) {
                        int tmp = max(p[j], num - 9 * (szof(p) - j - 1));
                        //cout << tmp << " " << num - tmp << " " << revsum[j + 1] << endl;
                        if (tmp == p[j] && num - tmp < revsum[j + 1]) {
                            ++tmp;
                        }
                        newn.puba(tmp);
                        num -= tmp;
                        if (tmp > p[j]) {
                            alr = true;
                        }                  
                    } else {
                        if ((szof(p) - j - 1) * 9 < num) {
                            int tmp = num - (szof(p) - j - 1) * 9;
                            num -= tmp;
                            newn.puba(tmp);
                        } else {
                            newn.puba(0);
                        }
                    }
                }
            } else {
                newn.puba(1);
                --num;
                for (int j = 0; j < szof(p); ++j) {
                    //cout << j << " " << num << endl;
                    if ((szof(p) - j - 1) * 9 < num) {
                        int tmp = num - (szof(p) - j - 1) * 9;
                        num -= tmp;
                        newn.puba(tmp);
                    } else {
                        newn.puba(0);
                    }
                }
            }
        } else {
            newn.puba(num % 9);
            if (newn[0] == 0) {
                newn[0] = 9;
            }
            for (int j = 0; j < (num + 8) / 9 - 1; ++j) {
                newn.puba(9);
            }
        }
        for (int j = 0; j < szof(newn); ++j) {
            cout << newn[j];
        }
        cout << endl;
        p = newn;
    }        

    return 0;
}