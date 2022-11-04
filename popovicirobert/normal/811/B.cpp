#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 1e4;

int v[MAXN + 1];
int fr[MAXN + 1];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    for(i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        memset(fr, 0, sizeof(fr));
        for(j = l; j <= r; j++)
            fr[v[j]]++;
        int cnt = 0;
        j = 1;
        while(cnt < x - l + 1) {
            cnt += fr[j];
            j++;
        }
        j--;
        if(j == v[x])
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}