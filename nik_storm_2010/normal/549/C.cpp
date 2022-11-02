#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool even(int k0, int k1) {
    return ((k0 * 2 + k1) % 2 == 0);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int k0 = 0;
    int k1 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            k0++;
        } else {
            k1++;
        }
    }
    int moves = n - k;
    if (moves == 0) {
        if (even(k0, k1)) {
            printf("Daenerys\n");
        } else {
            printf("Stannis\n");
        }
        return 0;
    }
    int stannis_first = 0;
    int daenerys_first = 0;
    if (moves % 2 == 0) {
        if (k0 > k1) {
            stannis_first = 1;
            daenerys_first = 0;
        } else {
            stannis_first = 0;
            daenerys_first = 1;
        }
    } else {
        if (k0 < k1) {
            stannis_first = 1;
            daenerys_first = 0;
        } else {
            stannis_first = 0;
            daenerys_first = 1;
        }
    }
    int current = 1;
    for (int i = 1; i <= moves; i++) {
        if (k0 == 0) {
            k1--;
            continue;
        }
        if (k1 == 0) {
            k0--;
            continue;
        }
        if (current == 1) {
            if (i == moves) {
                printf("Stannis\n");
                return 0;
            }
            if (stannis_first == 0) {
                k0--;
            } else {
                k1--;
            }
            current = 3 - current;
        } else {
            if (i == moves) {
                printf("Daenerys\n");
                return 0;
            }
            if (daenerys_first == 0) {
                k0--;
            } else {
                k1--;
            }
            current = 3 - current;
        }
    }
    
    if (even(k0, k1)) {
        printf("Daenerys\n");
    } else {
        printf("Stannis\n");
    }
    
    return 0;
}