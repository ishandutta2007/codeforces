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
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, x, y;
        cin >> n >> x >> y;
        if(x > y) swap(x, y);
        if(x != 0 || y == 0 || (n - 1) % y != 0){
            cout << "-1\n";
        }
        else{
            int las = 1;
            for(int i = 1; i <= n - 1; i ++ ){
                if((i - 1) % y == 0) las = i + 1;
                cout << las << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}