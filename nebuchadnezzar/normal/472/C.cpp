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
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;

int n;
vector <pair <string, int> > v;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.puba(mapa(s, i));
        cin >> s;
        v.puba(mapa(s, i));
    }
    sort(all(v));
    /*
    for (int i = 0; i < n * 2; ++i) {
        cout << v[i].ff << " " << v[i].ss << endl;
    }
    */
    int c = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        --num;
        while (c < n * 2 - 1 && v[c].ss != num) {
            ++c;
        }
        
        if (v[c].ss != num) {
            flag = false;
            break;
        }

        //cout << v[c].ff << " " << v[c].ss << endl;
    }
    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}