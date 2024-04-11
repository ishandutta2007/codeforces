#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll get(int id){
    cout << "? " << id + 1 << endl;
    fflush(stdout);
    ll xx;
    cin >> xx;
    return xx;
}

int main(){
    int n;
    ll k;
    cin >> n >> k;
    if(n <= 400){
        for(int i = 0 ;i < n; i ++ )
            get(0);
        vector<int> vv(n);
        for(int i = 0 ; i < n; i ++ ){
            vv[i]=get(i);
        }
        int nx;
        for(int i = 0 ; i < n; i ++ ){
            if(vv[i]==k){
                nx=vv[(i+1)%n];
                if(nx > k){
                    cout << "! " << i + 1 << endl;
                    exit(0);
                }
            }
        }
        return 0;
    }
    ll cc;
    int ix=-1;
    ll mx = 0;
    int ids = 0;
    while(1){
        ix = ((int)rng() % n + n) % n;
        cc=get(ix);
        if(cc != k){
            break;
        }
    }
    int dir = -1;
    if(cc < k){
        dir = +1;
    }
    while(1){
        ix = (ix + dir + n) % n;
        if(get(ix) == k){
            break;
        }
    }
    cout << "! " << ix + 1 << endl;
    return 0;
}