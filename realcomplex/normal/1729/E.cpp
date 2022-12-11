#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll ask(int x, int y){
    cout << "? " << x << " " << y << endl;
    ll res;
    cin >> res;
    return res;
}


int main(){
    ll r1, r2;
    for(int i = 1; i <= 25; i ++ ){
        r1 = ask(i * 2 - 1, i * 2);
        if(r1 == -1){
            r2 = ask(1, i * 2 - 1);
            if(r2 == -1){
                cout << "! " << i * 2 - 2 << endl;
            }
            else{
                cout << "! " << i * 2 - 1 << endl;
            }
            break;
        }
        r2 = ask(i * 2, i * 2 - 1);
        if(r1 != r2){
            cout << "! " << r1 + r2 << endl;
            break;
        }
    }
    return 0;
}