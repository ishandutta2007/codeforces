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
ll n,m,k,T,q,p;

vl A;

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> p >> k;
    ll p2 = p;
    ll mi = 1;
    for(int c1 = 0; c1 < 63; c1++){
        if(c1%2 == 0){
            A.push_back(p2%k);
            p2-=p2%k;
        }
        else{
            A.push_back((k-p2%k)%k);
            p2 += (k-p2%k)%k;
        }
        p2 /= k;
    }

    while(A[sz(A)-1] == 0)A.pop_back();
    if(p2 != 0){
        cout << "-1\n";
    }
    else{

        cout << sz(A) << "\n";
        for(int c1 = 0; c1 < sz(A); c1++){
            cout << A[c1] << " ";
        }

    }


    return 0;
}