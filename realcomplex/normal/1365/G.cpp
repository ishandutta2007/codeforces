#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
const int M = 13;

int a[N];

ll ask(vector<int> ids){
    if(ids.empty()) return 0ll;
    cout << "? " << ids.size() << " ";
    for(auto x : ids)
        cout << x+1 << " ";
    cout << endl;
    ll sol;
    cin >> sol;
    return sol;
}

int main(){
    vector<int> masks;
    for(int i = 0 ; i < (1 << M); i ++ ){
        if(__builtin_popcount(i) == 6){
            masks.push_back(i);
        }
    }
    int n;
    cin >> n;
    vector<ll> sub;
    for(int i = 0 ; i < M; i ++){
        vector<int> cur;
        for(int j = 0; j < n; j ++ ){
            if((masks[j] & (1 << i))) cur.push_back(j);
        }
        sub.push_back(ask(cur));
    }
    cout << "! ";
    ll cum;
    for(int i = 0 ; i < n; i ++ ){
        cum = 0;
        for(int j = 0 ; j < M ; j ++ ){
            if((masks[i] & (1 << j)) == 0)
                cum |= sub[j];
        }
        cout << cum << " ";
    }
    cout << endl;
    return 0;
}