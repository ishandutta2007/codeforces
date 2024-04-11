#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double fact(double n) {
    double value = 1;
    for (int i=1; i<=n; ++i) value*=i;
    return value;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
    double supposed = 0;
    for (int i=0; i<s1.size(); ++i) {
        if (s1[i] == '+') supposed++;
        else supposed--;
    }
    double actual = 0; double q = 0;
    for (int i=0; i<s2.size(); ++i) {
        if (s2[i] == '+') actual++;
        else if (s2[i] == '-') actual--;
        else q++;
    }
    double dif = (double)abs(supposed-actual);
    double Pneeded = (q+dif)/2;
    double Nneeded = q-Pneeded;

    double ans = 0;
	if (dif > q) {
        cout << ans << '\n';
        return 0;
    }

    ans = 1/pow(2, q)/fact(Nneeded)/fact(Pneeded)*fact(q);
    cout << setprecision(12) << ans << '\n';
	return 0;
}