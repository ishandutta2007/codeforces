#include <iostream>

using namespace std;

string a, b, c, d;
int s1, s2, s3, s4, s5;

int main() {
    cin >> a >> b >> c >> d;
    if (a[0] == '#') s1++;
    if (a[1] == '#') s1++;
    if (b[0] == '#') s1++;
    if (b[1] == '#') s1++;
    if (a[2] == '#') s2++;
    if (a[3] == '#') s2++;
    if (b[2] == '#') s2++;
    if (b[3] == '#') s2++;
    if (c[0] == '#') s3++;
    if (c[1] == '#') s3++;
    if (d[0] == '#') s3++;
    if (d[1] == '#') s3++;
    if (c[2] == '#') s4++;
    if (c[3] == '#') s4++;
    if (d[2] == '#') s4++;
    if (d[3] == '#') s4++;
    if (b[1] == '#') s5++;
    if (b[2] == '#') s5++;
    if (c[1] == '#') s5++;
    if (c[2] == '#') s5++;
    int v = 0;
    if (s1 <= 1 || s1 >= 3) v = 1;
    if (s2 <= 1 || s2 >= 3) v = 1;
    if (s3 <= 1 || s3 >= 3) v = 1;
    if (s4 <= 1 || s4 >= 3) v = 1;
    if (s5 <= 1 || s5 >= 3) v = 1;
    if (v) cout << "YES\n";
    else cout << "NO\n";
}