#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
#pragma comment (linker, "/STACK:64000000")

typedef long long ll;

#if _DEBUG 
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int cnt = 0;
    int dif1 = -1, dif2 = -1;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) continue;
        cnt++;
        if (dif1 == -1) dif1 = i;
        else dif2 = i;
    }

    if (cnt == 1) {
        cout << 2 << endl;
        return 0;
    }

    if (false && cnt > 2) {
        cout << 0 << endl;
        return 0;
    }
    string now1 = "", now2 = "";
    for (int i = dif1; i <= dif2; i++) {
        now1 += a[i];
        now2 += b[i];
    }
    int sz = (int)now1.size() - 1;
    cout << (now2[0] + now1 == now2 + now1[sz]) + (now1[0] + now2 == now1 + now2[sz]) << endl;
    return 0;
}