#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
int n,m,k,T,q;



int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;

    scanf("%d" , &n);
    scanf("%d" , &a);
    scanf("%d" , &b);
    vl ANS(n);
    bool fail = 1;
    for(int c1 = 0; c1 < n; c1++){
        if(a*c1 > n)break;
        if((n-a*c1)%b == 0){
            fail = 0;
            ll c2 = (n-a*c1)/b;

            for(int c3 = 0; c3 < c1; c3++){
                for(int c4 = c3*a; c4 < c3*a+a; c4++){
                    if(c4 < c3*a+a-1){
                        ANS[c4] = c4+1;
                    }
                    else{
                        ANS[c4] = c3*a;
                    }
                }
            }

            for(int c3 = 0; c3 < c2; c3++){
                ll down = c3*b  +  c1*a;
                ll up = c3*b+b  +  c1*a;
                for(int c4 = c3*b  +  c1*a; c4 < up; c4++){
                    if(c4 < up-1){
                        ANS[c4] = c4+1;
                    }
                    else{
                        ANS[c4] = down;
                    }
                }
            }
            break;
        }
    }
    if(fail){
        cout << "-1\n";
    }
    else{


        for(int c1 = 0; c1 < n; c1++){
            cout << ANS[c1]+1 << " ";
        }

    }

    return 0;
}