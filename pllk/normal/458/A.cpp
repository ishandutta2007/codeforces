#include <iostream>
#include <algorithm>

using namespace std;

string a, b;
int n;
char t1[101010];
char t2[101010];

int v1[101010];
int v2[101010];

int h[101010];

int main() {
    cin >> a >> b;
    n = max(a.size(), b.size());
    int c = n-1;
    for (int i = a.size()-1; i >= 0; i--) t1[c--] = a[i]-'0';
    c = n-1;
    for (int i = b.size()-1; i >= 0; i--) t2[c--] = b[i]-'0';
    for (int i = 0; i < n; i++) {
        if (t1[i] && t2[i]) {t1[i] = 0; t2[i] = 0;}
    }
    for (int i = n-1; i >= 0; i--) {
        if (t1[i] && v2[i+1]) {
            v2[i+1] = 0;
            h[i] = 1;
            for (int j = i+1; j <= n-1; j += 2) {
                h[j] = 1;
                if (v2[j+1]) {
                    h[j+1] = 1;
                    break;
                }
            }
            continue;
        }
        if (t2[i] && v1[i+1]) {
            v1[i+1] = 0;
            h[i] = 1;
            for (int j = i+1; j <= n-1; j += 2) {
                h[j] = 1;
                if (v1[j+1]) {
                    h[j+1] = 1;
                    break;
                }
            }
            continue;
        }
        if (t1[i] && t1[i+1]) {
            v1[i] = 1;
            v1[i+1] = 1;
        }
        if (t2[i] && t2[i+1]) {
            v2[i] = 1;
            v2[i+1] = 1;
        }
        if (t1[i] && v1[i+2]) {
            v1[i] = 1;
        }
        if (t2[i] && v2[i+2]) {
            v2[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (t1[i] && !h[i]) {
            cout << ">\n";
            return 0;
        }
        if (t2[i] && !h[i]) {
            cout << "<\n";
            return 0;
        }
    }
    cout << "=\n";
}