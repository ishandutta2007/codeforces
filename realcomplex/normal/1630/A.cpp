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
        if(k == 0){
            for(int i = 0 ; i < n/2; i ++ ){
                cout << i << " " << n - i - 1 << "\n";
            }
        }
        else if(k < n - 1){
            cout << k << " " << n - 1 << "\n";
            cout << 0 << " " << n - k - 1 << "\n";
            for(int i = 0 ; i < n / 2; i ++ ){
                if(i == 0 || i == k || i == n - k - 1) continue;
                cout << i << " " << n - i - 1 << "\n";
            }
        }
        else{
            if(n == 4){
                cout << "-1\n";
            }
            else{
                cout << n - 1 << " " << n - 2 << "\n";
                cout << 1 << " " << n - 3 << "\n";
                cout << 0 << " " << 2 << " ";
                for(int i = 0 ; i < n / 2; i ++ ){
                    if(i > 2){
                        cout << i << " " << n - i - 1 << "\n";
                    }
                }
            }
        }
    }
    return 0;
}