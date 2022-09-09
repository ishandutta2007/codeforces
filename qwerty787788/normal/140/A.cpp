#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
double R, r;
const double PI=2*asin(1.0);


int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        cin >> n >> R >> r;
        if (r > R) {
                cout << "NO" << endl;
                return 0;
        } else {
                if (n == 1) {
                        cout << "YES" << endl;
                        return 0;
                } else {
                        if (r > R- r+0.0000001) {
                                cout << "NO" << endl;
                                return 0;
                        } else {
                                double alpha = 2*n*asin(r/(R-r));
                                if (alpha <= 2*PI+0.0000001) {
                                        cout <<"YES";
                                        return 0;
                                } else {
                                        cout <<"NO";
                                        return 0;
                                }
                        }
                }
        }
        //
        return 0;
};