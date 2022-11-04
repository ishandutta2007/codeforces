#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 500;

int n;

inline char ask(int l1, int c1, int l2, int c2) {
    if(abs(l1 - l2) + abs(c1 - c2) < n - 1)
        return -1;
    fflush(stdout);
    cout << "? " << l1 << " " << c1 << " " << l2 << " " << c2 << "\n";
    string ans;
    cin >> ans;
    return ans == "YES";
}

vector < pair <int, int> > way1;
vector < pair <int, int> > way2;

void dfs1(int l, int c) {
    way1.push_back({l, c});
    if(l < n && ask(l + 1, c, n, n) == 1) {
        dfs1(l + 1, c);
    }
    else if(c < n && ask(l, c + 1, n, n) == 1) {
        dfs1(l, c + 1);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ios::sync_with_stdio(false);
    cin >> n;
    dfs1(1, 1);
    vector <char> sol1, sol2;
    for(int i = 0; i + 1 < way1.size(); i++) {
        if(way1[i].first == way1[i + 1].first) {
            sol1.push_back('R');
        }
        else {
            sol1.push_back('D');
        }
    }
    int l = n, c = n;
    for(int i = 0; i < n - 1; i++) {
        way1.pop_back();
        if(c > 0 && ask(way1.back().first, way1.back().second, l, c - 1) == 1) {
            c--;
            sol2.push_back('R');
        }
        else {
            l--;
            sol2.push_back('D');
        }
    }
    reverse(sol2.begin(), sol2.end());
    cout << "! ";
    for(auto it : sol1) {
        cout << it;
    }
    for(auto it : sol2) {
        cout << it;
    }
    //cin.close();
    //cout.close();
    return 0;
}