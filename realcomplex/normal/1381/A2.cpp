#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> seq(vector<int> aa){
    vector<int> rr;
    for(int i = 1; i < aa.size(); i ++ ){
        if(aa[i] != aa[i - 1]){
            rr.push_back(i - 1);
        }
    }
    if(aa.back() == 1){
        rr.push_back(aa.size() - 1);
    }
    return rr;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    char f;
    for(int i = 0 ; i < n; i ++ ){
        cin >> f;
        a[i] = f - '0';
    }
    for(int i = 0 ; i < n ; i ++ ){
        cin >> f;
        b[i] = f - '0';
    }
    vector<int> p = seq(a), q = seq(b);
    reverse(q.begin(), q.end());
    cout << p.size() + q.size() << " ";
    for(auto x : p)
        cout << x + 1 << " ";
    for(auto x : q)
        cout << x + 1 << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}