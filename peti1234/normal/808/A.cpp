#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int po=0; ; po++) {
        for (int i=1; i<=9; i++) {
            int x=i;
            for (int j=0; j<po; j++) x=10*x;
            if (x>n) {
                cout << x-n << "\n";
                return 0;
            }
        }
    }
    return 0;
}