#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int A[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    if(n % 2 == 1){
        cout << "-1\n";
        return;
    }
    vector<pii> p;
    for(int i = 1; i <= n; i += 2){
        if(A[i] == A[i + 1]){
            p.push_back(mp(i, i + 1));
        }
        else{
            p.push_back(mp(i, i));
            p.push_back(mp(i + 1, i + 1));
        }
    }
    cout << p.size() << "\n";
    for(auto i : p){
        cout << i.fi << " " << i.se << "\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}