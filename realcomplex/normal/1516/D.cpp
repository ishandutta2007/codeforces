#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
const int LOG = 19;
int A[N];
int up[LOG][N];
int low[N];
int las[N];

int main(){
    fastIO;
    for(int i = 2; i < N; i ++ ){
        if(low[i] == 0){
            low[i] = i;
            for(int j = i * 2; j < N ; j += i){
                if(low[j] == 0)
                    low[j] = i;
                else
                    low[j] = min(low[j], i);
            }
        }
    }
    //
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    int dd;
    up[0][n+1]=n+1;
    for(int i = n; i >= 1; i -- ){
        up[0][i] = n + 1;
        while(A[i] > 1){
            dd = low[A[i]];
            A[i] /= dd;
            if(las[dd] != 0 && las[dd] > i){
                up[0][i] = min(up[0][i], las[dd]);
            }
            las[dd] = i;
        }
        up[0][i]=min(up[0][i],up[0][i+1]);
    }
    for(int i = n + 1; i >= 1; i -- ){
        for(int j = 1; j < LOG; j ++ ){
            up[j][i]=up[j-1][up[j-1][i]];
        }
    }
    int li, ri;
    int total;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> li >> ri;
        total = 0;
        for(int lg = LOG - 1; lg >= 0 ;lg -- ){
            if(up[lg][li] <= ri){
                li = up[lg][li];
                total += (1 << lg);
            }
        }
        cout << total + 1 << "\n";
    }
    return 0;
}