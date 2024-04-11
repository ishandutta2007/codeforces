#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }


//    vector<int> xx = x, yy = y;


    while (true) {
        vector<int> c;
        for (int i = 0; i < n; i++) {
            if ((x[i] + y[i]) & 1) {
                c.push_back(i);
            }
        }
        if (c.size() > 0 && c.size() < n) {
            cout << c.size() << "\n";
            for (int x : c) {
                cout << x + 1 << " ";
            }
            cout << "\n";

//            vector<bool> z(n);
//            for (int x : c) z[x] = true;
//            set<int> b;
//            for (int i = 0; i < n; i++) {
//                for (int j = i + 1; j < n; j++) {
//                    if (z[i] == z[j]) {
//                        b.insert((xx[i] - xx[j]) * (xx[i] - xx[j]) +
//                                 (yy[i] - yy[j]) * (yy[i] - yy[j]));
////                        cerr << (xx[i] - xx[j]) * (xx[i] - xx[j]) +
////                                (yy[i] - yy[j]) * (yy[i] - yy[j]) << "\n";
//
//                    }
//                }
//            }
//            for (int i = 0; i < n; i++) {
//                for (int j = i + 1; j < n; j++) {
//                    if (z[i] != z[j]) {
////                        cerr << "? " << (xx[i] - xx[j]) * (xx[i] - xx[j]) +
////                                (yy[i] - yy[j]) * (yy[i] - yy[j]) << "\n";
//                        if (b.find((xx[i] - xx[j]) * (xx[i] - xx[j]) +
//                                         (yy[i] - yy[j]) * (yy[i] - yy[j])) != b.end()) {
//                            assert(false);
//                        }
//                    }
//                }
//            }

            return 0;
        }
        int q = (x[0] + y[0]) & 1;
        for (int i = 0; i < n; i++) {
            int xx = (x[i] + y[i] + q) / 2;
            int yy = (x[i] - y[i] + q) / 2;
            x[i] = xx;
            y[i] = yy;
        }
    }

    return 0;
}