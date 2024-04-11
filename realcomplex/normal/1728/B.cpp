#include <iostream>
#include <vector>
#include <algorithm>
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
        if(n % 2 == 0){
            for(int i = 0 ; i < n - 2; i ++ ){
                cout << n - 2 - i << " ";
            }
            cout << n - 1 << " " << n << "\n";
        }
        else{
            cout << n - 1 << " ";
            for(int i = n - 3; i >= 1; i -- ){
                cout << i << " ";
            }
            cout << n - 2 << " " << n << "\n";
        }
    }
    return 0;
}