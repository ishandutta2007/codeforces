#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int A[N];
int B[N];

void solve(){
    int n, k;
    cin >> n >> k;

    int m = n - k;
    int x;
    for(int i = 1; i <= n; i ++ ){
        A[i] = 0;
    }
    for(int id = 1; id <= n; id ++ ){
        cin >> x;
        B[id] = x;
        A[x] ++ ;
    }
    int cum = 0;
    int li = 1;
    int soln = (int)1e9;
    int xx=-1;
    int yy=-1;
    for(int ri = 1; ri <= n; ri ++ ){
        cum += A[ri];
        while((cum - A[li]) * 2ll >= n + k){
            cum -= A[li];
            li ++ ;
        }
        if(cum * 2ll >= n + k){
            if(ri - li + 1 <= soln){
                soln = ri - li + 1;
                xx = li;
                yy = ri;
            }
        }
    }
    cout << xx << " " << yy << "\n";
    int en = 0;
    int cur;
    int nex;
    int bal;
    for(int ii = 1; ii <= k; ii ++ ){
        cur = en + 1;
        bal = 0;
        while(bal < 1){
            en ++ ;
            if(B[en] >= xx && B[en] <= yy){
                bal ++ ;
            }
            else{
                bal -- ;
            }
        }
        if(ii == k)
            en = n;
        cout << cur << " " << en << "\n";
    }
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}