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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sol = abs(x2-x1) + abs(y2-y1);
        sol += 2*((x1!=x2)&(y1!=y2));
        cout << sol << "\n";
    }
    return 0;
}