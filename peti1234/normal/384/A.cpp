#include <iostream>

using namespace std;
int n;;
int main()
{
    cin >> n;
    cout << (n*n+1)/2 << "\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << ((i+j)%2 ? "." : "C");
        }
        cout << "\n";
    }
    return 0;
}