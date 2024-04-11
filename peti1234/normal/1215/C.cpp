#include <bits/stdc++.h>

using namespace std;

int n, s1, s2;
string x, y;
vector<int> ab, ba;
int main()
{
    cin >> n >> x >> y;
    for (int i=0; i<n; i++) {
        if (x[i]=='a' && y[i]=='b') {
            ab.push_back(i+1);
        }
        if (x[i]=='b' && y[i]=='a') {
            ba.push_back(i+1);
        }
    }
    s1=ab.size(), s2=ba.size();
    if ((s1+s2)%2) {
        cout << -1 << "\n";
        return 0;
    } else {
        cout << s1/2+s2/2+s1%2+s2%2 << "\n";
        for (int i=0; i+1<s1; i+=2) {
            cout << ab[i] << " " << ab[i+1] << "\n";
        }
        for (int i=0; i+1<s2; i+=2) {
            cout << ba[i] << " " << ba[i+1] << "\n";
        }
        if (s1%2) {
            int x=ab.back(), y=ba.back();
            cout << x << " " << x << "\n";
            cout << x << " " << y << "\n";
        }
    }
    return 0;
}