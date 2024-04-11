#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
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
typedef pair <int, int> pii;
const int MAXLS = 1005, MAXLT = 1e6 + 5;

char s[MAXLS], t[MAXLT];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    gets(s);
    gets(t);
    int ls = strlen(s);
    int lt = strlen(t);

    int c = 0;
    int from = 0;
    for (; from < lt; ++from) {
        if (t[from] == s[c]) {
            ++c;
            if (c == ls) {
                break;
            }
        }
    }

    c = ls - 1;
    int to = lt - 1;
    for (; to >= 0; --to) {
        if (t[to] == s[c]) {
            --c;
            if (c == -1) {
                break;
            }
        }
    }

    int tmp = to - from;    

    cout << max(tmp, 0) << endl;

    return 0;
}