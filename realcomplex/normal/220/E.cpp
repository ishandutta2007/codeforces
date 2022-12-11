#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

struct Tree{
    int tree[2 * N];
    int n;
    void upd(int id, int z){
        id += n;
        while(id>0){
            tree[id] += z ;
            id /= 2;
        }
    }
    int ask(int l, int r){
        l += n;
        r += n;
        int sum = 0;
        while(l <= r){
            if(l % 2 == 1) sum += tree[l ++ ];
            if(r % 2 == 0) sum += tree[r -- ];
            l /= 2;
            r /= 2;
        }
        return sum;
    }
    void init(int nn){
        n = nn;
        for(int i = 0 ; i < 2 * N ; i ++ )
            tree[i] = 0;
    }
};

int n;
Tree pref, suf;

ll inver = 0;

void add_pf(int x){
    inver += pref.ask(x+1,n-1);
    inver += suf.ask(0,x-1);
    pref.upd(x,1);
}

void rem_sf(int x){
    suf.upd(x,-1);
    inver -= pref.ask(x+1,n-1);
    inver -= suf.ask(0,x-1);
}

int main(){
    fastIO;
    ll k;
    cin >> n >> k;
    vector<ll> t;
    ll x[n];
    for(int i = 0 ; i < n; i ++ ){
        cin >> x[i];
        t.push_back(x[i]);
    }
    sort(t.begin(), t.end());
    for(int i = 0 ; i < n; i ++ ){
        x[i] = lower_bound(t.begin(), t.end(), x[i]) - t.begin();
    }
    pref.init(n);
    suf.init(n);
    for(int i = n-1 ; i >= 0; i -- ){
        inver += suf.ask(0,x[i]-1);
        suf.upd(x[i],+1);
    }
    int el = 0;
    ll answ = 0;
    for(int i = 0 ; i < n; i ++ ){
        if(i == el){
            rem_sf(x[i]);
            el ++ ;
        }
        if(i >= 0){
            add_pf(x[i]);
        }
        while(el < n && inver > k){
            rem_sf(x[el]);
            el ++ ;
        }
        answ += n-el;
    }
    cout << answ;
    return 0;
}