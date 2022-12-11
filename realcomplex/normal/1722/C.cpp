#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        string q[3][n];
        map<string, int> cnt;
        for(int i = 0 ; i < 3; i ++ ){
            for(int j = 0 ;j < n; j ++ ){
                cin >> q[i][j];
                cnt[q[i][j]] ++ ;
            }
        }
        int sol;
        for(int i = 0 ; i < 3; i ++ ){
            sol = 0;
            for(int j = 0 ; j < n; j ++ ){
                if(cnt[q[i][j]] == 1){
                    sol += 3;
                }
                else if(cnt[q[i][j]] == 2){
                    sol += 1;
                }
            }
            cout << sol << " ";
        }
        cout << "\n";
    }
    return 0;
}