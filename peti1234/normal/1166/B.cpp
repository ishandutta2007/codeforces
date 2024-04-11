#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i=5; i<=sqrt(n); i++) {
        if (n%i==0) {
            for (int j=0; j<n; j++) {
                int x=(j%i+j/i)%5;
                if (x==0) cout << "a";
                if (x==1) cout << "e";
                if (x==2) cout << "o";
                if (x==3) cout << "u";
                if (x==4) cout << "i";
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}