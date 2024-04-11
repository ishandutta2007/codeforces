#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 1e3+20,mod = 1e9+7,inf = 2e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1){
        cout << "Washington";
        return 0;
    }
    if (n == 2){
        cout << "Adams";
        return 0;
    }
    if (n == 3){
        cout << "Jefferson";
        return 0;
    }
    if (n == 4){
        cout << "Madison";
        return 0;
    }
    if (n == 5){
        cout << "Monroe";
        return 0;
    }
    if (n == 6){
        cout << "Adams";
        return 0;
    }
    if (n == 7){
        cout << "Jackson";
        return 0;
    }
    if (n == 8){
        cout << "Van Buren";
        return 0;
    }
    if (n == 9){
        cout << "Harrison";
        return 0;
    }
    if (n == 10){
        cout << "Tyler";
        return 0;
    }
    if (n == 11){
        cout << "Polk";
        return 0;
    }
    if (n == 12){
        cout << "Taylor";
        return 0;
    }
    if (n == 13){
        cout << "Fillmore";
        return 0;
    }
    if (n == 14){
        cout << "Pierce";
        return 0;
    }
    if (n == 15){
        cout << "Buchanan";
        return 0;
    }
    if (n == 16){
        cout << "Lincoln";
        return 0;
    }
    if (n == 17){
        cout << "Johnson";
        return 0;
    }
    if (n == 18){
        cout << "Grant";
        return 0;
    }
    if (n == 19){
        cout << "Hayes";
        return 0;
    }
    if (n == 20){
        cout << "Garfield";
        return 0;
    }
    if (n == 21){
        cout << "Arthur";
        return 0;     
    }
    if (n == 22 || n == 24){
        cout << "Cleveland";
        return 0;
    }
    if (n == 23){
        cout << "Harrison";
        return 0;
    }
    if (n == 25){
        cout << "McKinley";
        return 0;
    }
    if (n == 26){
        cout << "Roosevelt";
        return 0;
    }
    if (n == 27){
        cout << "Taft";
        return 0;
    }
    if (n == 28){
        cout << "Wilson";
        return 0;     
    }
    if (n == 29){
        cout << "Harding";
        return 0;
    }
    if (n == 30){
        cout << "Coolidge";
        return 0;
    }
    if (n == 31){
        cout << "Hoover";
        return 0;
    }
    if (n == 32){
        cout << "Roosevelt";
        return 0;
    }
    if (n == 33){
        cout << "Truman";
        return 0;
    }
    if (n == 34){
        cout << "Eisenhower";
        return 0;
    }
    if (n == 35){
        cout << "Kennedy";
        return 0;
    }
    if (n == 36){
        cout << "Johnson";
        return 0;
    }
    if (n == 37){
        cout << "Nixon";
        return 0;
    }
    if (n == 38){
        cout << "Ford";
        return 0;
    }
    if (n == 39){
        cout << "Carter";
        return 0;
    }
    cout << "Reagan";


}