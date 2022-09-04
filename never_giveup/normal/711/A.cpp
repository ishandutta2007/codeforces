#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int n, m;

char q[maxn][4];

bool is = 0;

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> q[i][0] >> q[i][1] >> q[i][2] >> q[i][2] >> q[i][3];
        if (!is && q[i][0] == q[i][1] && q[i][0] == 'O')
            is = 1, q[i][0] = '+', q[i][1] = '+';
        if (!is && q[i][2] == q[i][3] && q[i][2] == 'O')
            is = 1, q[i][2] = '+', q[i][3] = '+';
    }
    if (!is){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << q[i][0] << q[i][1] << '|' << q[i][2] << q[i][3] << '\n';
}