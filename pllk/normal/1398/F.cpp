#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
string s;
vector<pair<int,int>> v;

#define N (1<<20)
#define INF 999999999

int pp[2*N];

void setVal(int k, int x) {
    k += N;
    pp[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        pp[k] = min(pp[2*k],pp[2*k+1]);
    }
}

int getMin(int a, int b) {
    a += N; b += N;
    int u = INF;
    while (a <= b) {
        if (a%2 == 1) u = min(u,pp[a++]);
        if (b%2 == 0) u = min(u,pp[b--]);
        a /= 2; b /= 2;
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s;
    s = "#"+s;
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] != '1') c0++;
        else c0 = 0;
        if (s[i] != '0') c1++;
        else c1 = 0;
        int u = max(c0,c1);
        v.push_back({u,i});
        setVal(i,i);
    }
    sort(v.begin(),v.end());
    int k = 0;
    cout << n << " ";
    for (int i = 2; i <= n; i++) {
        while (k < n && v[k].first < i) {
            setVal(v[k].second,INF);
            k++;
        }
        int u = 1;
        int c = 0;
        while (true) {
            int p = getMin(u+i-1,n);
            if (p == INF) break;
            c++;
            u = p+1;
        }
        cout << c << " ";
    }
    cout << "\n";
}