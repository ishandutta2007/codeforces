#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> y;

int main() {
    cin >> n >> k;
    y.resize(n);
    for (int i = 0; i < n; i++) cin >> y[i];
    int c = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (y[i]+k > 5) continue;
        c++;
        if (c%3 == 0) t++;
    }
    cout << t << endl;
}