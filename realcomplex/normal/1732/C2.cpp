#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int A[N];
ll P[N];
ll Q[N];

ll f(int l, int r){
    return P[r] - P[l - 1] - (Q[r] ^ Q[l - 1]);
}

void solve(){
    int n, q;
    cin >> n >> q;
    set<int> ids;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        if(A[i] != 0) ids.insert(i);
        P[i] = P[i - 1] + A[i];
        Q[i] = (Q[i - 1] ^ A[i]);
    }
    int li, ri;
    ll maxi;
    int len;
    int lf;
    int rf;
    for(int qi = 1; qi <= q; qi ++ ){
        cin >> li >> ri;
        maxi = f(li, ri);
        vector<int> fa, fb;
        fa.push_back(li);
        fb.push_back(li);
        auto it = ids.lower_bound(li);
        while(it != ids.end() && fa.size() < 32){
            if(*it > ri) break;
            fa.push_back(*it);
            it ++ ;
        }
        it = ids.upper_bound(ri);
        while(it != ids.begin() && fb.size() < 32){
            it -- ;
            if(*it < li) break;
            fb.push_back(*it);
        }
        len = ri - li + 1;
        lf = li;
        rf = ri;
        for(auto xi : fa){
            for(auto yi : fb){
                if(xi <= yi){
                    if(f(xi, yi) == maxi){
                        if(yi - xi + 1 <= len){
                            lf = xi;
                            rf = yi;
                            len = yi - xi + 1;
                        }
                    }
                }
            }
        }
        cout << lf << " " << rf << "\n";
    }
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}