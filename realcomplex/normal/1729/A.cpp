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
        int a, b, c;
        cin >> a >> b >> c;
        int da = a - 1;
        int db = abs(c - b) + c - 1;
        if(da < db){
            cout << "1\n";
        }
        else if(da > db){
            cout << "2\n";
        }
        else{
            cout << "3\n";
        }
    }
    return 0;
}