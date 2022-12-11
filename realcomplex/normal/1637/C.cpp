#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
ll A[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        ll res = 0;
        int odd = 0;
        int big = 0;
        for(int i = 1; i <= n; i ++ ){
            cin >> A[i];
            if(i > 1 && i < n) {
                res += A[i];
                if(A[i] % 2 == 1){
                    res ++ ;
                    odd ++ ;
                }
                if(A[i] > 1) big ++ ;
            }
        }
        bool can = false;
        if(odd == 0){
            can = true;
        }
        else if(big >= 1 && n > 3){
            can = true;
        }
        if(can)
            cout << res / 2 << "\n";
        else
            cout << "-1\n";


    }
    return 0;
}