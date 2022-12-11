#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int dif[N];
int sum[N];
int A[N];
int main(){
    fastIO;
    int n, q, k;
    cin >> n >> q >> k;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        if(i){
            dif[i]=(A[i]-A[i-1]-1);
            sum[i]=sum[i-1]+dif[i];
        }
    }
    int l, r;
    int soln;
    for(int i = 1; i <= q; i ++ ){
        cin >> l >> r;
        soln = 2*(sum[r]-sum[l]);
        soln += A[l]-1;
        soln += k-A[r];
        cout << soln << "\n";
    }
    return 0;
}