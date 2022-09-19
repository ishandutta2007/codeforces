#include <bits/stdc++.h>

using namespace std;
string a, b;
int n;
int p=0;
int main()
{
    cin >> n;
    cin >> a >> b;
    for (int i=0; i<n; i++) {
        if (a[i]!=b[i]) {
            if (i!=n-1 && a[i]!=a[i+1] && a[i]==b[i+1]) {
                i++;
            }
            p++;
        }
    }
    cout << p << endl;
    return 0;
}