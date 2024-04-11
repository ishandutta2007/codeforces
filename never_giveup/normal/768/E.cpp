#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 1e6 + 100;

int n;

int a[maxn];

int go(int x, vector<int> v){
    bool mex[62];
    for (int i = 0; i < 62; i++)
        mex[i] = 0;
    sort(v.begin(), v.end());
    vector<int> p = v;
    int ind = 0;
    for (int i = 1; i <= x; i++){
        while (ind < v.size() && v[ind] < i)
            ind++;
        if (ind == v.size() || v[ind] != i){
            p.push_back(i);
            mex[go(x - i, p)] = 1;
            p.pop_back();
        }
    }
    for (int i = 0; i < 62; i++)
        if (!mex[i])
            return i;
}

int f[1000];

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    int now = 1;
    for (int i = 2; now <= 60; i++){
        for (int j = 0; j < i; j++)
            f[now] = i - 1, now++;
    }
    cin >> n;
    int x = 0, y;
    for (int i = 0; i < n; i++)
        cin >> y, x ^= f[y];
    if (x == 0)
        cout << "YES";
    else
        cout << "NO";
}