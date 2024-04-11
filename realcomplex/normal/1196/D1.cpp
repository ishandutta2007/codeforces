#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int f[3][3][N];

int main(){
    fastIO;
    int qr;
    cin >> qr;
    for(int tt = 1; tt <= qr; tt ++ ){
        int n, k;
        cin >> n >> k;
        
        for(int j =0 ; j < 3; j ++ ) for(int z = 0 ;z < 3 ;z ++ )
        for(int i = 0 ; i <= n; i ++ )
            f[j][z][i] = 0;
        char ki;
        int val;
        for(int i = 1; i <= n; i ++ ){
            cin >> ki;
            if(ki == 'R')
                val = 0;
            else if(ki == 'G')
                val = 1;
            else
                val = 2;
            f[i%3][val][i]++;
        }
        for(int i = 1; i <= n; i ++ ){
            for(int j = 0 ; j < 3; j ++ ) for(int z =0 ; z < 3; z ++ )
                f[j][z][i] += f[j][z][i-1];
        }
        int res = 0;
        int good;
        for(int i = 1; i <= n - k + 1; i ++ ){
            for(int j = 0 ; j < 3; j ++ ){
                good = 0;
                good += f[j][i%3][i + k - 1]-f[j][i%3][i-1];
                good += f[(j+1)%3][(i+1)%3][i + k - 1] - f[(j+1)%3][(i+1)%3][i - 1];
                good += f[(j+2)%3][(i+2)%3][i + k - 1] - f[(j+2)%3][(i+2)%3][i - 1];
                res = max(res, good);
            }
        }
        cout << k - res << "\n";
    }
    return 0;
}