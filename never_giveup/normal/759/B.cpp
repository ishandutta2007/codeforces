#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100, maxt = 2000;

int n;

map<int, int> q;

int main(){
    #ifndef ONPC
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    #else
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    int last;
    cin >> last;
    q[last] = 20;
    cout << 20 << '\n';
    for (int i = 1; i < n; i++){
        int t;
        cin >> t;
        q[t] = q[last] + 20;
        map<int, int> :: iterator it = q.lower_bound(t - 90 + 1);
        if (it == q.begin())
            q[t] = min(q[t], 50);
        else
            it--, q[t] = min(q[t], it->second + 50);
        it = q.lower_bound(t - 1440 + 1);
        if (it == q.begin())
            q[t] = min(q[t], 120);
        else
            it--, q[t] = min(q[t], it->second + 120);
        cout << q[t] - q[last] << '\n';
        last = t;
    }
}