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
ll n,m,k,q,w,h,T;


vector<ll> mids;
bool chosen[100001] = {0};

ll A[100001] = {0};

ll calls(ll l, ll r){
    if(l == r-1)return 1;
    mids.push_back((r+l)/2);
    return 1 + calls(l,(r+l)/2) + calls((r+l)/2,r);
}

void sorta(ll l, ll r, ll l2, ll r2){
    if(l == r-1){
        A[l] = l2;
        return;
    }
    ll mid = (l+r)/2;
    ll mid2 = (l2+r2)/2;
    if(chosen[mid]){
        sorta(l,mid,l2,mid2);
        sorta(mid,r,mid2,r2);
    }
    else{
        sorta(l,mid,mid2+(r-l)%2,r2);
        sorta(mid,r,l2,mid2+(r-l)%2);
    }
    return;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;


    cin >> n >> k;
    c = calls(0,n);
    if(k%2 == 0 || k > c){
        cout << "-1\n";
    }
    else{
        for(ll c1 = 0; c1 < c-k; c1+=2){
            chosen[mids[sz(mids)-1-c1/2]] = 1;
        }
        sorta(0,n,0,n);
        for(ll c1 = 0; c1 < n; c1++)cout << A[c1]+1 << " ";
    }
    return 0;
}