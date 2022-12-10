#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 0){
        int a = 1;
        cout << "YES" << endl;
        cout << a << endl << a << endl << 3 * a << endl << 3 * a << endl;
        return 0;
    }
    if(n == 1){
        int a;
        cin >> a;
        cout << "YES" << endl;
        cout << a << endl << 3 * a << endl << 3 * a << endl;
        return 0;
    }
    if(n == 2){
        int a, b;
        cin >> a >> b;
        if(b < a)
            swap(a, b);
        if(b > 3 * a)
            cout << "NO" << endl;
        else if(b == 3 * a){
            cout << "YES" << endl;
            cout << a << endl
                << b << endl;
        }
        else if(a == b){
            cout << "YES" << endl;
            cout << 3 * a << endl << 3 * a << endl;
        }
        else{
            cout << "YES" << endl;
            cout << a + (3 * a - b) << endl
                << 3 * a << endl;
        }
    }
    if(n == 3){
        int a[3];
        rep(i, 3)
            cin >> a[i];
        sort(a, a + 3);
        bool x = false;
        if(a[0] * 3 < a[2]){
            cout << "NO" << endl;
            x = true;
        }
        else if(a[0] * 3 == a[2]){
            x = true;
            cout << "YES" << endl;
            int t = 2 * a[0];
            if(a[1]<=t){
                cout << a[2] - a[1] + a[0] << endl;
            }
            else{
                cout << a[2] - a[1] + a[0] << endl;
            }
        }
        else if(a[0] % 2 == a[1] % 2){
            if(a[2] % 3 == 0 && a[0] - (a[2] / 3) == a[2] - a[1]){
                x = true;
                cout << "YES" << endl;
                cout << a[2] / 3 << endl;
            }
        }
        else if(a[1] % 2 == a[2] % 2){
            if(3 * a[0] >= a[2] && 3 * a[0] - a[2] == a[1] - a[0]){
                x = true;
                cout << "YES" << endl;
                cout << 3 * a[0] << endl;
            }
        }
        else{
            cout << "NO" << endl;
            x = true;
        }
        if(!x)
            cout << "NO" << endl;
    }
    if(n == 4){
        int a[4];
        rep(i, 4)
            cin >> a[i];
        sort(a, a+4);
        if(a[0] * 3 == a[3] && a[1] - a[0] == a[3] - a[2]){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}