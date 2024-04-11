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

ll n,m,T,k,d;
const ll big = 1000000007;

vl A;
ll l;

ll geta(ll i){
    if(i < 0 || i >= n)return -12;
    return A[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

   ll segs = 0;

    cin >> n >> m >> l;
    ll prev = -1;

    for(int c1 = 0; c1<n; c1++){
        cin >> a;
        A.push_back(a);
        if(prev <= l && a > l){
            segs++;
        }
        prev = a;
    }

    for(int c1 = 0; c1 < m; c1++){
        cin >> a;
        if(a == 0){
            cout << segs << "\n";
        }
        else{
            cin >> a >> b;
            a--;

            if(A[a] <= l && A[a]+b > l){

                if(geta(a-1) <= l && geta(a+1) <= l){
                    segs++;
                }
                else{

                    if(geta(a-1) > l && geta(a+1) > l){
                        segs--;
                    }

                }

            }

            A[a] += b;

        }
    }

    return 0;
}