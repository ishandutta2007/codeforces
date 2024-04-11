#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int i = -1;
    while (n > 0) {
        i += 1;
        n -= 5 * pow(2, i);
    }
    n += 5 * pow(2, i);
    i = pow(2, i);
    
    int j;
    for (j = i; j <= 5 * i; j+= i) {
        if (n <= j)
            break;
    }
    
    j /= i;
    
    if (j == 1)
        cout << "Sheldon";
    else if (j == 2)
        cout << "Leonard";
    else if (j == 3)
        cout << "Penny";
    else if (j == 4)
        cout << "Rajesh";
    else
        cout << "Howard";
    
    return 0;
}