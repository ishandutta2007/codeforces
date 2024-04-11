#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> a >> b >> k;

    if(k == 0){
        cout << "Yes\n";
        rep(c1,0,2){
            rep(c2,0,b){
                cout << "1";
            }
            rep(c2,0,a){
                cout << "0";
            }
            cout << "\n";
        }
        return 0;
    }

    if(a == 0){
        cout << "No\n";
        return 0;
    }

    b--;
    a--;

    if(k > a+b || b == 0){
        cout << "No\n";
    }
    else{
        string s1 = "0";
        string s2 = "1";
        k--;
        while(k > 0 && a > 0){
            s1 += '0';
            s2 += '0';
            k--;
            a--;
        }
        while(k > 0 && b > 1){
            s1 += '1';
            s2 += '1';
            b--;
            k--;
        }
        s1 += '1';
        s2 += '0';
        while(a > 0){
            s1 += '0';
            s2 += '0';
            a--;
        }
        while(b > 0){
            s1 += '1';
            s2 += '1';
            b--;
        }
        reverse(all(s1));
        reverse(all(s2));
        cout << "Yes\n";
        cout << s1 << "\n";
        cout << s2 << "\n";
    }

    return 0;
}