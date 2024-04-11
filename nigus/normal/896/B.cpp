#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,q,h,T,k;


ll A[1001] = {0};
bool check(){
    ll prev = -1;
    for(ll c1 = 0; c1 < n; c1++){
        if(A[c1] < prev)return 0;
        if(A[c1] == 0)return 0;
        prev = A[c1];
    }
    return 1;
}

bool next(){
    ll c;
    cin >> c;
    if(c > k/2){
        ll bak = 0;
        for(ll c1 = 0; c1 < n; c1++){
            if(c > A[c1])bak = c1;
        }
        A[bak] = c;
        cout << bak+1 << "\n";
        fflush(stdout);
        return check();
    }
    else{
        ll fram = n-1;
        for(ll c1 = n-1; c1 >= 0; c1--){
            if(c < A[c1] || A[c1] == 0)fram = c1;
        }
        A[fram] = c;
        cout << fram+1 << "\n";
        fflush(stdout);
        return check();
    }
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;


    cin >> n >> m >> k;

    while(!next()){};


    return 0;
}