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
        int n, k;
        cin >> n >> k;
        int a;
        int take = k;
        int low;
        for(int i = 1; i <= n; i ++ ){
            cin >> a;
            if(i == n){
                cout << a + k - take;
            }
            else{
                low = min(a, take);
                a -= low;
                take -= low;
                cout << a << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}