#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s, t;
int n;

int z[2100*2100][26];
int b[2100*2100][2];
int zk;

int main() {
    cin >> s >> t;
    n = s.size();
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i; j < n; j++) {
            int u = s[j]-'a';
            if (!z[k][u]) {
                z[k][u] = ++zk;
            }
            k = z[k][u];
            b[k][0] = i+1;
            b[k][1] = j+1;
        }
    }
    reverse(s.begin(),s.end());
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i; j < n; j++) {
            int u = s[j]-'a';
            if (!z[k][u]) {
                z[k][u] = ++zk;
            }
            k = z[k][u];
            b[k][0] = n-i;
            b[k][1] = n-j;
        }
    }
    int n = t.size();
    int k = 0;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int u = t[i]-'a';
        if (z[k][u] == 0) {
            v.push_back({b[k][0],b[k][1]});
            k = 0;
            if (z[k][u] == 0) {
                cout << "-1\n";
                return 0;
            }
        }
        k = z[k][u];
    }
    v.push_back({b[k][0],b[k][1]});
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << "\n";
}