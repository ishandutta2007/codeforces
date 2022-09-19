#include <bits/stdc++.h>

using namespace std;
int n;
bool prime(int x)
{
    for (int i=2; i<x; i++) {
        if (x%i==0) {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i=1; i<=1000; i++) {
       if (prime(n*i+1)) {
        cout << i
        << endl;
        return 0;
        }
    }

    return 0;
}