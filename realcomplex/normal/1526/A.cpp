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
        vector<int> A(n * 2);
        for(int i = 0 ; i < n * 2; i ++ ){
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        int p = 0, q = n * 2 - 1;
        for(int i = 0 ; i < n * 2; i ++ ){
            if(i % 2 == 0){
                cout << A[p] << " ";
                p ++ ;
            }
            else{
                cout << A[q] << " ";
                q -- ;
            }
        }
        cout << "\n";
    }
    return 0;
}