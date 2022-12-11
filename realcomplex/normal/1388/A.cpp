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
        ll n;
        cin >> n;
        if(n < 31)
            cout << "NO\n";
        else{
            cout << "YES\n";
            if(n == 36){
                cout << "5 6 10 15\n";
            }
            else if(n == 44){
                cout << "6 7 10 21\n";
            }
            else if(n == 40){
                cout << "1 10 14 15\n";
            }
            else{
                ll a = 1, b = 6, c = 10, d = 14;
                a += n - (a + b + c + d);
                cout << a << " " << b << " " << c << " " << d << "\n";
            }
        }
    }
    return 0;
}