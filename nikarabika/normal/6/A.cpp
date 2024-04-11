//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

char get(int a[]) {
    if (a[0] + a[1] == a[2])
        return 1;
    return 2 * (a[0] + a[1] > a[2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a[4];
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a, a + 4);
    int b[3];
    bool segment = false;
    for (int i = 0; i < 4; i++) {
        int siz = 0;
        for (int j = 0; j < 4; j++)
            if (i != j)
                b[siz++] = a[j];
        int val = get(b);
        if (val == 2)
            return cout << "TRIANGLE\n", 0;
        if (val)
            segment = true;
    }
    if (segment)
        return cout << "SEGMENT\n", 0;
    cout << "IMPOSSIBLE\n", 0;
    return 0;
}