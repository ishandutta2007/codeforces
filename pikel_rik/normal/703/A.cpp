#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int c1 = 0, c2 = 0;
    
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i])
            c1 += 1;
        else if (b[i] > a[i])
            c2 += 1;
    }
    if (c1 > c2)
        cout << "Mishka";
    else if (c2 > c1)
        cout << "Chris";
    else
        cout << "Friendship is magic!^^";
        return 0;
}