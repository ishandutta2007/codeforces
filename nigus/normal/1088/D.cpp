#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

int n,m,T,k,d;
const ll big = 1000000007;

int ask(ll x, ll y){
    cout << "? " << x << " " << y << "\n";
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

int main() {
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,e;
    int prev = ask(0,0);
    a = 0;
    b = 0;
    ll x = 0;
    ll y = 0;
    for(int c1 = 29; c1 >= 0; c1--){
        if(prev == 0){
            e = ask(a+(1<<c1),b);
            if(e == -1){
                x += (1<<c1);
                y += (1<<c1);
                a += (1<<c1);
                b += (1<<c1);
            }
        }
        else{
            if(prev == 1){
                e = ask(a+(1<<c1),b+(1<<c1));
                if(e != prev){
                    x += (1<<c1);
                    a += (1<<c1);
                    prev = ask(a,b);
                }
                else{
                    e = ask(a+(1<<c1),b);
                    if(e != prev){
                        x += (1<<c1);
                        y += (1<<c1);
                        a += (1<<c1);
                        b += (1<<c1);
                    }
                }
            }
            else{

                e = ask(a+(1<<c1),b+(1<<c1));
                if(e != prev){
                    y += (1<<c1);
                    b += (1<<c1);
                    prev = ask(a,b);
                }
                else{
                    e = ask(a,b+(1<<c1));
                    if(e != prev){
                        x += (1<<c1);
                        y += (1<<c1);
                        a += (1<<c1);
                        b += (1<<c1);
                    }
                }


            }

        }
    }

    cout << "! " << x << " " << y << "\n";
    fflush(stdout);

    return 0;
}