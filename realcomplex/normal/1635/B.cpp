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
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> A[i];
        }
        vector<int> local;
        for(int i = 1; i + 1 < n; i ++ ){
            if(A[i] > A[i - 1] && A[i] > A[i + 1]){
                local.push_back(i);
            }
        }
        int res = 0;
        int C = 0;
        vector<int> lis;
        for(int i = 0; i < local.size(); i ++ ){
            C ++ ;
            lis.push_back(local[i]);
            if(i + 1 == local.size() || local[i + 1] - local[i] > 2){
                for(int j = 0 ; j + 1 < lis.size(); j += 2){
                    A[lis[j] + 1] = max(A[lis[j]], A[lis[j+1]]);
                    res ++ ;
                }
                if(C % 2 == 1){
                    A[lis.back()] = max(A[lis.back()-1],A[lis.back()+1]);
                    res ++ ;
                }
                lis.clear();
                C = 0;
            }
        }
        cout << res << "\n";
        for(int i = 0 ; i < n; i ++ ){
            cout << A[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}