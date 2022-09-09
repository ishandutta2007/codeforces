#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, x, y;
int xm[100005], ym[100005];
vector <pair <int, int> > mem;

int main() {
    cin >> n;
    //int num = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ++xm[x];
        ++ym[y];
        mem.push_back(make_pair(x, y));
    }
    //long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cout << n - 1 + xm[mem[i].second] << " " << n - 1 - xm[mem[i].second] << endl;
    }


    return 0;
}