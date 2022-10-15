#include <iostream>

using namespace std;

int as, av;
int bs, bv;
int n, k;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k%2 == 0) {as++; av = i+1;}
        if (k%2 == 1) {bs++; bv = i+1;}
    }
    if (as == 1) cout << av << endl;
    else cout << bv << endl;
}