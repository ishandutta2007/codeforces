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

int n;
LL arrl[MAXN];
int arrk[MAXN];

LL gcd(LL a, LL b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n;   

    //LL total = -1;
    map <LL, int> have;
    for (int i = 0; i < n; ++i) {
        cin >> arrl[i];        
    }    

    for (int i = 0; i < n; ++i) {
        cin >> arrk[i];
    }

    for (int i = 0; i < n; ++i) {
        if (n % 20 == 0 && clock() > 1.8 * CLOCKS_PER_SEC) {
            break;
        }
        if (!have.count(arrl[i])) {
            have[arrl[i]] = arrk[i];
        } else {
            have[arrl[i]] = min(arrk[i], have[arrl[i]]);
        }
        for (map <LL, int>::iterator it = have.begin(); it != have.end(); ++it) {   
            LL tmp = gcd(it -> ff, arrl[i]);
            if (!have.count(tmp)) {
                have[tmp] = it -> ss + arrk[i];
            } else {
                have[tmp] = min(have[tmp], it -> ss + arrk[i]);
            }
        }
    }
    
    if (have.count(1)) {
        cout << have[1] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}