#include <bits/stdc++.h>

using namespace std;
long long a, b;
vector<long long> x;
int main()
{
    cin >> a >> b;
    while (b>a) {
        x.push_back(b);
        if (b%2==0) {
            b=b/2;
        }
        else {
            if (b%10==1) {
                b=b/10;
            }
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    x.push_back(a);
    if (a>b) {
        cout << "NO";
        return 0;
    }
    if (a==b) {
        cout << "YES" << endl;
        cout << x.size() << endl;
        reverse(x.begin(), x.end());
        for (int i=0; i<x.size(); i++) {
            cout << x[i] << " ";
        }
    }
    return 0;
}