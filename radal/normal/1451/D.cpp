#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e6+30,mod = 1e9+7,inf=1e12;
const long double eps = 0.0001;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll d,k,turn=0;
        ll x=0,y=0;
        cin >> d >> k;
        while (x*x + y*y <= d*d){
            if (turn%2) y+=k;
            else x+=k;
            turn = 1-turn;
        }
        if (turn) cout << "Utkarsh" << endl;
        else cout << "Ashish" << endl;
    }
    return 0;
}