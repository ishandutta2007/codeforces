#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define puba push_back 

using namespace std;

int x, k, type, d1, d2, numr;
vector <int> mas;

int main() {
    cin >> x >> k;
    for (int i = 0; i < k; ++i) {
        cin >> type;
        if (type == 1) {
            cin >> d2 >> d1;
            mas.puba(d2);
            mas.puba(d1);
            numr += 2;
        } else {
            cin >> d2;
            mas.puba(d2);
            ++numr;
        }   
    }
    mas.puba(0);
    mas.puba(x);
    sort(mas.begin(), mas.end());
    int minn = 0;
    for (int i = 1; i < (int) mas.size(); ++i) {
        minn += (mas[i] - mas[i - 1]) / 2;
    }
    cout << minn << " " << x - 1 - numr;

    return 0;
}