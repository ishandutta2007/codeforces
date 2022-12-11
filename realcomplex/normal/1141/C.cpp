#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n;
    cin >> n;
    int q[n];
    for(int i = 1 ; i < n; i ++ ){
        cin >> q[i];
    }
    ll v = 0;
    ll gr = 1, sm = n;
    for(int i = 1; i < n; i ++ ){
        v += q[i];
        if(q[i] == 0){
            cout << -1;
            exit(0);
        }
        if(v < 0){
            gr = max(gr, -v + 1);
        }
        else{
            sm = min(sm,  n - v);
        }
    }
    if(gr > sm){
        cout << -1;
        exit(0);
    }
    set<int> per;
    int x = gr;
    per.insert(x);
    for(int i = 1; i < n; i ++ ){
        x += q[i];
        if(x<=0 || x > n){
            cout << -1;
            exit(0);
        }
        per.insert(x);
    }
    if(per.size() != n){
        cout << -1 << "\n";
        exit(0);
    }
    x = gr;
    cout << x << " ";
    for(int i = 1; i < n; i ++ ){
        x += q[i];
        cout << x << " ";
    }
    return 0;
}