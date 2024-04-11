#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 1000;

vector <int> g[MAXN + 1];
int fr[MAXN + 1];

int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    vector <int> arr;
    for(i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        if(max(a, b) < n) {
            cout << "NO";
            return 0;
        }
        if(min(a, b) == n) {
            cout << "NO";
            return 0;
        }
        arr.push_back(min(a, b));
        fr[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    vector <int> un_used;
    for(i = 1; i < n; i++) {
        if(fr[i] > i) {
            cout << "NO";
            return 0;
        }
    }
    int sz = 0, pos = 0;
    int last = 0;
    for(auto it : arr) {
        last++;
        while(last < it) {
            un_used.push_back(last);
            last++;
        }
        sol[++sz] = it;
        fr[it]--;
        if(pos + fr[it] <= un_used.size()) {
            for(i = pos; i < pos + fr[it]; i++) {
                sol[++sz] = un_used[i];
            }
            pos += fr[it];
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    sol[++sz] = n;
    if(sz < n) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    for(i = 1; i < n; i++) {
        cout << sol[i] << " " << sol[i + 1] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}