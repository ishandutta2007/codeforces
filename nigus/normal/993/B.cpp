#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

int n,m,k,q,p;

struct pt{
int x,y;
};

vector<pt> A1;
vector<pt> A2;

int ans = 0;
bool theyknow = 1;


void test(int d){

    bool possible = 0;

    for(int x = 1; x < 10; x++){
        for(int y = 1; y < 10; y++){
            if(x == y || x == d || y == d)continue;
            bool yes1 = 0;
            bool yes2 = 0;
            for(int c1 = 0; c1 < n; c1++){
                if(min(x,d) == A1[c1].x && max(x,d) == A1[c1].y){
                    yes1 = 1;
                }
            }
            for(int c1 = 0; c1 < m; c1++){
                if(min(y,d) == A2[c1].x && max(y,d) == A2[c1].y){
                    yes2 = 1;
                }
            }
            if(yes1 && yes2){
                possible = 1;

                for(int c1 = 0; c1 < m; c1++){
                    ll y2 = -1;
                    if(A2[c1].x == x)y2 = A2[c1].y;
                    if(A2[c1].y == x)y2 = A2[c1].x;
                    if(y2 != -1 && y2 != d){
                        theyknow = 0;
                    }
                }


                for(int c1 = 0; c1 < n; c1++){
                    ll x2 = -1;
                    if(A1[c1].x == y)x2 = A1[c1].y;
                    if(A1[c1].y == y)x2 = A1[c1].x;
                    if(x2 != -1 && x2 != d){
                        theyknow = 0;
                    }
                }


            }
        }
    }

    if(possible){

        if(ans != 0)ans = -1;

        if(ans == 0){
            ans = d;
        }

    }

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        A1.push_back({min(a,b),max(a,b)});
    }
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        A2.push_back({min(a,b),max(a,b)});
    }

    for(int c1 = 1; c1 < 10; c1++){
        test(c1);
    }

    if(ans == -1 && theyknow)ans = 0;
    cout << ans << "\n";
    return 0;
}