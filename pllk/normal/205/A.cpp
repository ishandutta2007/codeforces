#include <iostream>

using namespace std;

int n;
int p = 1000000000+1;
int s;
int t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < p) {
            p = t;
            s = i+1;
        } else if (t == p) {
            s = 0;
        }
    }
    if (s == 0) cout << "Still Rozdil" << endl;
    else cout << s << endl;
}