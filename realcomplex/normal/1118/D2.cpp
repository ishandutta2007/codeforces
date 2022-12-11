#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

ll m;
vector<ll> cup;

bool can(int x){
    ll sum = 0;
    int t;
    for(int i = 0; i < (int)cup.size(); i ++ ){
        t = (i/x);
        sum += max(0ll, cup[i] - t);
    }
    return sum >= m;
}

int main(){
    fastIO;
    int n;
    cin >> n >> m;
    ll a;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> a;
        cup.push_back(a);
    }
    sort(cup.begin(), cup.end());
    reverse(cup.begin(), cup.end());
    if(!can(n)){
        cout << "-1\n";
        return 0;
    }
    int lf = 1, rf = n;
    int md;
    while(lf < rf){
        md = (lf + rf) / 2;
        if(can(md)){
            rf = md;
        }
        else{
            lf = md + 1;
        }
    }
    cout << rf << "\n";
    return 0;
}