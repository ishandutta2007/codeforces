#include <bits/stdc++.h>

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
        int n;
        cin >> n;
        vector<int> A(n);
        int sol = 0;
        for(int i = 0 ; i < n; i ++ ){
            cin >> A[i];
        }
        for(int i = 0 ; i < n; i ++ ){
            for(int j = i + 1; j < n; j ++ ){
                if(A[i] % 2 == 0 || A[j] % 2 == 0){
                    sol ++ ;
                }
                else{
                    if(__gcd(A[i], A[j]) > 1){
                        sol ++ ;
                    }
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}