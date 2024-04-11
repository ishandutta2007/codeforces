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
    for(int t = 0; t < tc; t ++ ){
        int n;
        cin >> n;
        int c2 = 0, c3 = 0;
        while(n % 2 == 0){
            n /= 2;
            c2 ++ ;
        }
        while(n % 3 == 0){
            n /= 3;
            c3 ++ ;
        }
        if(n != 1 || c2 > c3){
            cout << "-1\n";
        }
        else{
            cout << c3 + (c3 - c2) << "\n";
        }
    }
    return 0;
}