#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c[10];
int n;
vector<pair<vector<int>,int>> v;
int r[101010];

bool lol(pair<vector<int>,int> &a, pair<vector<int>,int> &b) {
    for (int i = 0; i < 6; i++) {
        if (a.first[i] == 0 && b.first[i] == 0) continue;
        if (a.first[i] == 1 && b.first[i] == 0) return 1;
        if (a.first[i] == 0 && b.first[i] == 1) return 0;
        if (i < 5 && a.first[i+1] == 1 && b.first[i+1] == 0) return 0;
        if (i < 5 && a.first[i+1] == 0 && b.first[i+1] == 1) return 1;
    }
    return a.second < b.second;
}

int main() {
    for (int i = 0; i < 6; i++) cin >> c[i];
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        vector<int> u;
        if (x == "S") u = {1,0,0,0,0,0};
        if (x == "M") u = {0,1,0,0,0,0};
        if (x == "L") u = {0,0,1,0,0,0};
        if (x == "XL") u = {0,0,0,1,0,0};
        if (x == "XXL") u = {0,0,0,0,1,0};
        if (x == "XXXL") u = {0,0,0,0,0,1};
        if (x == "S,M") u = {1,1,0,0,0,0};
        if (x == "M,L") u = {0,1,1,0,0,0};
        if (x == "L,XL") u = {0,0,1,1,0,0};
        if (x == "XL,XXL") u = {0,0,0,1,1,0};
        if (x == "XXL,XXXL") u = {0,0,0,0,1,1};
        v.push_back(make_pair(u,i));
    }
    sort(v.begin(),v.end(),lol);
    for (int i = 0; i < v.size(); i++) {
        bool ok = false;
        for (int j = 0; j < 6; j++) {
            if (v[i].first[j] && c[j]) {
                c[j]--;
                r[v[i].second] = j;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (r[i] == 0) cout << "S\n";
        if (r[i] == 1) cout << "M\n";
        if (r[i] == 2) cout << "L\n";
        if (r[i] == 3) cout << "XL\n";
        if (r[i] == 4) cout << "XXL\n";
        if (r[i] == 5) cout << "XXXL\n";
    }
}