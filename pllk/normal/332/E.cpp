#include <iostream>

using namespace std;

string p, s;
int k;
int t[3000];
int f[3000];
bool v;

void tutki(int m) {
    //cout << m << endl;
    int a = m-1;
    int q = 0;
    int w = (p.length()/k)*m;
    int z = s.length()-w;
    int y = p.length()%k;
    if (z < 0 && z > y) return;
    if (w > s.length()) return;
    //cout << w << " " << z << " " << y << endl;
    int g = 0;
    for (int i = k-1; i >= 0; i--) {
        int h = a;
        t[i] = 0;
        int qq = q;
        if (a == -1) goto ohi;
        if (i > y-1 && g+z == m) goto ohi;
        for (int j = i; j < p.length(); j +=k) {
            if (h >= s.length() || s[h] != p[j]) goto ohi;
            qq++;
            h += m;
        }
        //cout << "ok! " << i << endl;
        q = qq;
        t[i] = 1;
        a--;
        g++;
        ohi: ;
    }
    //cout << q << " " << s.length() << " " << a << endl;
    if (q == s.length() && a == -1) {
        v = true;
        for (int i = 0; i < k; i++) {
            if (f[i] < t[i]) return;
            if (f[i] > t[i]) break;
        }
        for (int i = 0; i < k; i++) f[i] = t[i];
    }
}

int main() {
    getline(cin, p);
    getline(cin, s);
    cin >> k;
    for (int i = 0; i < k; i++) f[i] = 1;
    for (int i = 1; i <= k; i++) tutki(i);
    if (v) {
        for (int i = 0; i < k; i++) cout << f[i];
        cout << endl;
    } else cout << 0 << endl;
}