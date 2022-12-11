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
        vector<int> A(n), B(n);
        for(int i = 0 ;i  < n; i ++ ){
            cin >> A[i];
        }
        for(int i = 0 ;i  < n; i ++ ){
            cin >> B[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int res = 1;
        for(int i = 0 ; i < n;i  ++ ){
            if(A[i] != B[i] && A[i] + 1 != B[i]){
                res = 0;
            }
        }
        if(res == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}