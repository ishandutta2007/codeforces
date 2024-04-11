#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const int N = (int)2e5 + 9;

int main(){
    fastIO;
    int n;
    cin >> n;
    int a;
    vector<int> t;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        t.push_back(a);
    }
    sort(t.begin(), t.end());
    set<int> use;
    for(auto x : t){
        if(!use.count(x - 1) && x - 1 > 0){
            use.insert(x-1);
        }
        else if(!use.count(x)){
            use.insert(x);
        }
        else{
            use.insert(x + 1);
        }
    }
    cout << use.size() << "\n";
    return 0;
}