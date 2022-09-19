#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int sum=(n%2 ? 2:4);
    for (int i=n-1; i>=4; i-=2) {
        sum+=i;
    }
    cout << sum << "\n";
    if (n%2) for (int i=1; i<=2; i++) cout << "3 1 2 3\n";
    else {
        for (int i=1; i<=4; i++) {
            cout << 3 << " ";
            for (int j=1; j<=4; j++) {
                if (j!=i) {
                    cout << j << " ";
                }
            }
            cout << "\n";
        }
    }
    for (int i=(n%2 ? 4 : 5); i+1<=n; i+=2) {
        for (int j=0; j<2*i; j+=2) {
            cout << (j%i==0 || (j+1)%i==0 ? 3 : 4) << " ";
            cout << i << " ";
            if (j%i) cout << j%i << " ";
            cout << i+1 << " ";
            if ((j+1)%i) cout << (j+1)%i << " ";
            cout << "\n";
        }
    }
    return 0;
}