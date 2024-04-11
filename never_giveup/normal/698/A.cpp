#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 1e3 + 100, inf = 1e9 + 100;

int q[maxn][3];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        q[i][0] = 1 + min(q[i - 1][0], min(q[i - 1][1], q[i - 1][2]));
        q[i][1] = inf;
        q[i][2] = inf;
        if (x == 1 || x == 3)
            q[i][1] = min(q[i - 1][0], q[i - 1][2]);
        if (x == 2 || x == 3)
            q[i][2] = min(q[i - 1][0], q[i - 1][1]);
    }
    cout << min(q[n][0], min(q[n][1], q[n][2]));
}