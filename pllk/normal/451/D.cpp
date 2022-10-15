#include <iostream>
#include <vector>

using namespace std;

#define ll long long

string s;
int n;
vector<ll> v;

ll c[2][2], z[2];
int x, y;

int main() {
    cin >> s;
    n = s.size();
    int i = 0;
    while (true) {
        int p = 0;
        for (int j = i; j < n; j++) {
            if (s[i] != s[j]) break;
            p++;
        }
        v.push_back(p);
        i += p;
        if (i == n) break;
    }
    n = v.size();
    for (int i = 0; i < n; i++) {
        z[0] += c[x][y%2]*(v[i]/2);
        z[1] += c[x][y%2]*((v[i]+1)/2);
        z[0] += c[x][1-y%2]*((v[i]+1)/2);
        z[1] += c[x][1-y%2]*(v[i]/2);

        ll s1, s2;
        if (v[i]%2 == 1) {
            s1 = v[i]*(v[i]+1)/2;
            s2 = (v[i]/2)*(v[i]/2+1);
        } else {
            s1 = v[i]*(v[i]+1)/2;
            s2 = s1-(v[i]/2)*(v[i]/2+1);
        }

        z[0] += s2;
        z[1] += s1-s2;

        c[x][y%2] += (v[i]+1)/2;
        c[x][1-y%2] += v[i]/2;
        x = 1-x;
        y += v[i];
    }
    cout << z[0] << " " << z[1] << "\n";
}