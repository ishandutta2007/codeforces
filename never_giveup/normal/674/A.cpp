#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e3 + 10;

int n, m, q[maxn], a[maxn], b[maxn];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i], q[i]--;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            a[j] = 0;
        int mx = 0, ind = 0;
        for (int j = i; j < n; j++){
            a[q[j]]++;
            if (a[q[j]] > mx || (a[q[j]] == mx && q[j] < ind))
                mx = a[q[j]], ind = q[j];
            b[ind]++;
        }
    }
    for (int i = 0; i < n; i++)
    cout << b[i] << ' ';
}