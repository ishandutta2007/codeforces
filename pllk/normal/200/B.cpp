#include <iostream>
#include <iomanip>

using namespace std;

int n;
int p;
double s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        s += p;
    }
    cout << setprecision(9) << s/n << endl;
}