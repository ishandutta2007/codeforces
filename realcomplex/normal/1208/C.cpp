#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
int a[N][N];
int rw[N];
int cl[N];

int n;
bool check(){  
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            rw[i] ^= a[i][j];
            cl[j] ^= a[i][j];
        }
    }
    for(int i = 1; i < n; i ++ )
        if(rw[i] != rw[i - 1] || cl[i] != cl[i - 1])
            return false;
    return cl[0] == rw[0];
}

int main(){
    fastIO;
    cin >> n;
    int k = n/4;
    int z;
    for(int i = 0 ; i < k ; i ++ ){
        z = 4 * i * n;
        for(int t = 0 ;t < 4; t ++ ){
            for(int j = 0 ; j < n ; j ++ ){
                a[4 * i + t][j] = z + 4 * j + t;
            }
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}