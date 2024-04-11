#include <bits/stdc++.h>

using namespace std;
int b, n;
int t[100001];
bool c;
long long sum;
int main()
{
    cin >> b >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    if (b%2==0) {
        if (t[n]%2==0) {
            c=true;
        } else {
            c=false;
        }
    } else {
        if (sum%2==0) {
            c=true;
        } else {
            c=false;
        }
    }
    if (c) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }
    return 0;
}