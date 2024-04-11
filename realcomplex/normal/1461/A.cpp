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
    for(int t = 1; t <= tc; t ++ ){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i ++ ){
            cout << char('a'+(i%3));
        }
        cout << "\n";
    }
}