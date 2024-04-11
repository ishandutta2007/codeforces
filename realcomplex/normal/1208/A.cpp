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
    int testc;
    cin >> testc;
    for(int i = 1; i <= testc; i ++ ){
        int a, b, n;
        cin >> a >> b >> n;
        if(n % 3 == 0)
            cout << a << "\n";
        else if(n % 3 == 1)
            cout << b << "\n";
        else
            cout << (a ^ b) << "\n";
    }
    return 0;
}