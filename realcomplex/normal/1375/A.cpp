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
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        int n;
        cin >> n;
        int a;
        for(int i = 0 ; i < n; i ++ ){
            cin >> a;
            if(i % 2 == 0)
                cout << abs(a) << " ";
            else
                cout << -abs(a) << " ";
        }
        cout << "\n";
    }
    return 0;
}