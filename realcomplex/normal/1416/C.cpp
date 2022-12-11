#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int LOG = 31;
vector<vector<int>> G[LOG];


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    G[LOG-1]={{}};
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        G[LOG-1].back().push_back(a[i]);
    }
    ll inv = 0;
    ll sol = 0;
    ll i0 = 0, i1 = 0;
    ll c0 = 0, c1 = 0;
    for(int i = LOG-2; i >= 0 ; i -- ){
        i0 = 0, i1 = 0;
        for(auto x : G[i + 1]){
            vector<int> n1, n2;
            c0 = 0, c1 = 0;
            for(auto y : x){
                if((y & (1 << i))){
                    n1.push_back(y);
                    i1 += c0;
                    c1 ++ ;
                }
                else{
                    n2.push_back(y);
                    i0 += c1;
                    c0 ++ ;
                }
            }
            if(!n1.empty()){
                G[i].push_back(n1);
            }
            if(!n2.empty()){
                G[i].push_back(n2);
            }
        }
        if(i1 < i0){
            sol ^= (1ll << i);
            inv += i1;
        }
        else{
            inv += i0;
        }
    }
    cout << inv << " " << sol << "\n";
    return 0;
}