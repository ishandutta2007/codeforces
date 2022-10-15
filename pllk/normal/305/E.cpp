#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int n;
int g[5050];
vector<pair<int,int>> z;

int main() {
    for (int i = 1; i < 5050; i++) {
        int m[5050] = {0};
        for (int j = 0; j < i; j++) {
            int u = g[max(j-1,0)]^g[max(i-j-2,0)];
            m[u] = 1;
        }
        for (int j = 0; ; j++) {
            if (m[j] == 0) {g[i] = j; break;}
        }
    }
    cin >> s;
    n = s.size();
    int v = -1;
    int x = 0;
    int c = 0;
    for (int i = 1; i < n-1; i++) {
        if (s[i-1] == s[i+1]) {
            if (v == i-1) c++;
            else c = 1;
            v = i;
        } else if (v == i-1) {
            z.push_back(make_pair(i-c, c));
            x ^= g[c];
        }
    }
    if (v == n-2) {
        z.push_back(make_pair(n-1-c, c));
        x ^= g[c];
    }
    if (x == 0) {
        cout << "Second\n";
    } else {
        cout << "First\n";
        for (int i = 0; i < z.size(); i++) {
            int a = z[i].first;
            int b = z[i].second;
            if (x^g[b] < g[b]) {
                for (int j = 0; j < b; j++) {
                    int u = g[max(j-1,0)]^g[max(b-j-2,0)];
                    if (u == (x^g[b])) {
                        cout << a+j+1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
}