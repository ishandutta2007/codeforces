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
        int n;
        cin >> n;
        for(int i = 0 ;i  < n; i ++ ){
            for(int j =0 ; j  < n; j ++ ){
                cout << ((i+j)%n==n-2 || (i+j)%n==n-1) << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}