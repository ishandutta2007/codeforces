#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool comp(pii A, pii B){
    if(A.fi == B.fi){
        return A.se > B.se;
    }
    return A.fi < B.fi;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pii> A(n - 1);
    int ap, bp;
    cin >> ap >> bp;
    for(int i = 0 ; i < n - 1; i ++ ){
        cin >> A[i].fi >> A[i].se;
    }
    if(k <= ap){
        cout << "YES\n";
        return;
    }
    if(k > ap + bp){
        cout << "NO\n";
        return;
    }
    sort(A.begin(), A.end());

    for(auto x : A){
        if(x.fi >= k - bp){
            cout << "YES\n";
            return;
        }
    }
    vector<int> pref((int)A.size());
    for(int i = 0 ; i < A.size(); i ++ ){
        pref[i] = A[i].fi + A[i].se;
        if(i) pref[i]=max(pref[i],pref[i-1]);
    }
    int reach = k - bp;
    for(int i = (int)A.size() - 1; i >= 0 ; i -- ){
        if(i){
            if(pref[i - 1] >= reach){
                cout << "YES\n";
                return;
            }
        }
        if(A[i].fi + A[i].se < reach){
            cout << "NO\n";
            return;
        }
        if(reach <= A[i].fi){
            cout << "YES\n";
            return;
        }
        reach -= A[i].se;
    }
    cout << "NO\n";
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