#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll lcm(ll a, ll b){
    return a*b/__gcd(a,b);
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        int n;
        cin >> n;
        if(n % 2 == 0)
            cout << n/2 << " " << n/2 << "\n";
        else{
            int a = 1, b = n - 1;
            for(int i = 1; i < min(n, 40000); i ++ ){
                if(lcm(a,b) > lcm(i,n-i)){
                    a = i;
                    b = n - i;
                }
                if(i > 1 && n % i == 0){
                    int f = n / i;
                    if(lcm(f, n - f) < lcm(a, b)){
                        a = f;
                        b = n - f;
                    }
                }
            }
            cout << a << " " << b << "\n";
        }
    }
    return 0;
}