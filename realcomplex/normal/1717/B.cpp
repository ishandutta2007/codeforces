#include <iostream>

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
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        for(int ii = 1 ; ii <= n; ii ++ ){
            for(int jj = 1; jj <= n; jj ++ ){
                if((ii + jj) % k == (r + c) % k){
                    cout << 'X';
                }
                else{
                    cout << '.';
                }
            }
            cout << "\n";
        }
    }
    return 0;
}