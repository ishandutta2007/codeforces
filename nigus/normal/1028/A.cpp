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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q;

bool inbounds(ll i, ll j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

ll DX[4] = {0,1,0,-1};
ll DY[4] = {1,0,-1,0};

vector<string> A;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;
        A.push_back(s);
    }

    ll i = 0;
    ll j = 0;
    ll dist = -1;

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            if(A[c1][c2] == 'B'){
                ll temp = 1000;
                for(int c3 = 0; c3 < 4; c3++){
                    ll temp2 = 0;
                    ll x = c1+DX[c3];
                    ll y = c2+DY[c3];
                    while(inbounds(x,y) && A[x][y] == 'B'){
                        temp2++;
                        x += DX[c3];
                        y += DY[c3];
                    }
                    temp = min(temp,temp2);
                }
                if(temp > dist){
                    dist = temp;
                    i = c1;
                    j = c2;
                }
            }
        }
    }

    cout << i+1 << " " << j+1 << "\n";


    return 0;
}