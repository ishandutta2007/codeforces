#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 101;
int n , k , mx;
int main(){
    cin >> n >> k;
    mx = ( ( n * n ) / 2 ) + ( n & 1 );
    if ( k > mx ){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                if(1^((i&1)^(j&1)) && k){
                    cout << "L";
                    --k;
                }
                else{
                    cout << "S";
                }
            }
            cout << "\n";
        }
    }
}