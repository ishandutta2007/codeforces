#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
int res[N][N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n;
        cin >> n;
        for(int i = 0; i < n; i ++ ){
            for(int j = i + 1; j < n; j ++ ){
                res[i][j]=0;
            }
        }
        int k = (n-1)/2;
        int p, q;
        for(int i = 0; i < n; i ++ ){
            for(int j = 1; j <= k ; j ++ ){
                p = i;
                q = (i + j) % n;
                if(q < p){
                    res[q][p]=-1;
                }
                else{
                    res[p][q]=+1;
                }
            }
        }
        for(int i = 0 ; i < n; i ++ ){
            for(int j = i + 1; j < n; j ++ ){
                cout << res[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}