#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc;t  ++ ){
        int n;
        cin >> n;
        if(n == 1){
            cout << "9\n";
        }
        else if(n == 2){
            cout << "98\n";
        }
        else if(n >= 3){
            cout << "989";
            for(int i = 3; i < n; i ++ ){
                cout << (i-3)%10;
            }
            cout << "\n";
        }
    }
    return 0;
}