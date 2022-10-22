#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

int arr[20][361], n, a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr[0][0] = 1;
    for (int i=1; i<=n; i++){
        cin >> a;
        for (int j=0; j<361; j++){
            if (arr[i-1][j] == 0) continue;
            arr[i][(j+a)%360] = 1;
            arr[i][(j-a+360)%360] = 1;
        }
    }
    if (arr[n][0] == 1) cout << "YES";
    else cout << "NO";
}