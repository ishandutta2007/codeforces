#include <bits/stdc++.h>
#define ll long long


using namespace std;


pair <int, int> v[6];

bool cmp(pair <int, int> a, pair <int, int> b) {
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, h, m, s, t1, t2;
    ios::sync_with_stdio(false);
    cin >> h >> m >> s >> t1 >> t2;
    if(t1 > t2)
        swap(t1, t2);
    h = (h % 12) * 5;
    v[0] = {h, 0};
    v[1] = {m, 0};
    v[2] = {s, 0};
    v[3] = {(t1 % 12) * 5, 1};
    v[4] = {(t2 % 12) * 5, 1};
    sort(v, v + 4 + 1, cmp);
    if(v[0].second == 1 && v[4].second == 1) {
        cout << "YES";
        return 0;
    }
    for(i = 1; i <= 4; i++) {
        if(v[i].second == 1 && v[i - 1].second == 1) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}