#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
string z;
set<int> s[2];

void end(int x) {
    if (x == 1) cout << "tokitsukaze\n";
    if (x == 2) cout << "quailty\n";
    if (x == 3) cout << "once again\n";
    exit(0);
}

int find_before(int w, int k) {
    auto it = s[w].lower_bound(k);
    if (it == s[w].begin()) return -1;
    it--;
    return *it;
}

int find_after(int w, int k) {
    auto it = s[w].upper_bound(k);
    if (it == s[w].end()) return -1;
    return *it;
}

bool check(vector<int> v, vector<int> b, int ai, int bi) {
    vector<int> u;
    for (auto x : v) if (x != -1 && (x < ai || x > bi)) u.push_back(x);
    for (auto x : b) u.push_back(x);
    sort(u.begin(),u.end());
    if (u.size() <= 1) return true;
    return u[u.size()-1]-u[0]+1 <= k;
}

int main() {
    cin >> n >> k;
    cin >> z;
    for (int i = 0; i < n; i++) {
        if (z[i] == '0') s[0].insert(i);
        else s[1].insert(i);
    }
    for (int w = 0; w <= 1; w++) {
        int i1 = find_after(w,-1);
        int i2 = find_before(w,n);
        if (i2-i1+1 <= k) end(1);
    }
    int c1 = 0, c2 = 0;
    for (int i = 0; i+k <= n; i++) {
        int c = 0;
        for (int w = 0; w <= 1; w++) {
            vector<int> v0, v1;
            vector<int> b0, b1;
            v0.push_back(find_after(0,-1));
            v0.push_back(find_before(0,i));
            v0.push_back(find_after(0,i+k-1));
            v0.push_back(find_before(0,n));
            if (w == 0) {
                b0.push_back(i);
                b0.push_back(i+k-1);
            }
            v1.push_back(find_after(1,-1));
            v1.push_back(find_before(1,i));
            v1.push_back(find_after(1,i+k-1));
            v1.push_back(find_before(1,n));
            if (w == 1) {
                b1.push_back(i);
                b1.push_back(i+k-1);
            }
            if (check(v0,b0,i,i+k-1) || check(v1,b1,i,i+k-1)) c++;
        }
        c1++;
        if (c == 2) c2++;
    }
    if (c1 == c2) end(2);
    end(3);
}