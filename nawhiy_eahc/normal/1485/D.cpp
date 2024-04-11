#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[502][502], b[502][502];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i + j)%2) b[i][j] = 720720;
            else b[i][j] = 720720 - a[i][j] * a[i][j] * a[i][j] * a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}