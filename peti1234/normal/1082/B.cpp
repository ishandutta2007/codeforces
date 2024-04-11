#include <bits/stdc++.h>

using namespace std;
string s;
int c=0;
int n;
int maxi=0;
int a, ag;
int main()
{
    cin >> n;
    cin >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='G') {
            c++;
        }
    }
    for (int i=0; i<n; i++) {
        if (s[i]=='G') {
            a++;
            ag++;
        } else {
            if (c!=ag) {
                ag++;
            }
            maxi=max(maxi, ag);
            ag=a;
            a=0;
        }
    }
    if (c!=ag) {
        ag++;
    }
    maxi=max(maxi, ag);
    cout << maxi << endl;
    return 0;
}