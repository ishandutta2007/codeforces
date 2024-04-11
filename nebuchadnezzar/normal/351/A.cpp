#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define puba push_back
#define mapa make_pair

using namespace std;

int n;
double num, sumd, sum, numz;
bool used[4000];

vector <double> mas;
vector <pair <double, pair <int, int> > > maso;

int main() {
    cin >> n;

    for (int i = 0; i < 2 * n; ++i) {
        cin >> num;
        if (num == int(num)) {
            ++numz;
        }
        sumd += int(num);
        sum += num;
        //maso.puba(mapa(int(num) + 1 - num, i));
    }

    double ans = 100000000;
    for (int i = n - numz; i <= n; ++i) {
        ans = min(ans, abs(sum - (sumd + i)));
    }

    printf("%.3f", ans);

    return 0;
}