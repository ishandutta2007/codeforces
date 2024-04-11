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

int n;
string s;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n; 
    cin >> s;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            bool flag = true;
            for (int k = 0; k < 5; ++k) {
                if (i + j * k >= n || s[i + j * k] == '.') {
                    flag = false;
                }
            }
            if (flag) {
                cout << "yes\n";
                return 0;
            }
        }
    }

    cout << "no\n";
    return 0;
}