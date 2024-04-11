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
    for(int iq = 1; iq <= tc; iq ++) {
        int n, k;
        cin >> n >> k;
        if(k > (n + 1) / 2){
            cout << "-1\n";
        }
        else{
            for(int i = 0 ; i < n; i ++ ){
                for(int j = 0 ;j < n; j ++ ){
                    if(k > 0 && i == j && i % 2 == 0){
                        cout << "R";
                        k -- ;
                    }
                    else{
                        cout << ".";
                    }
                }
                cout << "\n";
            }
        }
    }
    return 0;
}