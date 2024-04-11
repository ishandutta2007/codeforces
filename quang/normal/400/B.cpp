#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 1010

using namespace std;

int n, m;
string matrix[N];
set <int> M;

int Timg(int u) {
    for(int i = 0; i < matrix[u].size(); i++)
        if(matrix[u][i] == 'G') return i;
}

int Tims(int u) {
    for(int i = 0; i <matrix[u].size(); i++)
        if(matrix[u][i] == 'S') return i;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> matrix[i];
    for(int i = 0; i < n; i++) {
        int vtg = Timg(i);
        int vts = Tims(i);
        if(vtg > vts) {
            cout << -1;
            return 0;
        }
        else M.insert(vts - vtg);
    }
    cout << M.size();
    return 0;
}