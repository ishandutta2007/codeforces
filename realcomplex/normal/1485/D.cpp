#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int a;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            cin >> a;
            if((i + j) % 2 == 0) cout << 720720 << " ";
            else cout << a * a * a * a + 720720 << " ";
        }
        cout << "\n";
    }
    return 0;
}