#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 10;
int A[N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        for(int i = 0 ; i <= n + 1; i ++ ){
            A[i] = 0;
        }
        for(int i = 1 ; i <= n; i ++ ){
            cin >> A[i];
        }
        ll res = 0;
        for(int i = 1; i <= n; i ++ ){
            res += max(0, A[i] - A[i - 1]);
            res += max(0, A[i] - A[i + 1]);
        }
        for(int i = 1; i <= n; i ++ ){
            if(A[i] > A[i - 1] && A[i] > A[i + 1]){
                res -= A[i] - max(A[i - 1], A[i + 1]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}