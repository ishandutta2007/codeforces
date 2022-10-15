#include <iostream>

using namespace std;

int x, k;
int t[4040];
int pt, st;

int main() {
    cin >> x >> k;
    for (int i = 0; i < k; i++) {
        int d, a, b;
        cin >> d;
        if (d == 1) {
            cin >> a >> b;
            t[a] = 1;
            t[b] = 1;
        } else {
            cin >> a;
            t[a] = 1;
        }
    }
    int c = 0;
    for (int i = 1; i < x; i++) {
        if (t[i] == 0) c++;
        else {
            pt += (c+1)/2;
            st += c;
            c = 0;
        }
    }
    pt += (c+1)/2;
    st += c;
    cout << pt << " " << st << endl;
}