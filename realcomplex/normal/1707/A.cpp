#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int n, q;
int A[N];
bool sol[N];

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        sol[i] = false;
    }
    int qq = 0;
    for(int i = n; i >= 1; i -- ){
        if(qq >= A[i]){
            sol[i] = true;
        }
        else{
            if(qq < A[i]){
                if(qq < q){
                    qq ++ ;
                    sol[i] = true;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cout << sol[i];
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}