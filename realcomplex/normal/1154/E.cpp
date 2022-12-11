#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)2e5 + 9;
int team[N];

int bit;
int k;

set<pii> st;
set<pii> pos;
void make_a_move(){
    auto it = st.end();
    -- it;
    auto ti = pos.lower_bound(mp(it->se, it->fi));
    vector<pii> er;
    er.push_back((*ti));
    auto nx = ti;
    nx ++ ;
    int cnt = k;
    while(nx != pos.end() && cnt > 0){
        -- cnt;
        er.push_back((*nx));
        ++ nx;
    }
    cnt = k;
    nx = ti;
    while(nx != pos.begin() && cnt > 0){
        -- nx;
        -- cnt;
        er.push_back((*nx));
    }
    for(auto p : er){
        team[p.fi] = bit;
        pos.erase(p);
        st.erase(mp(p.se, p.fi));
    }
}

int main(){
    fastIO;
    int n;
    cin >> n >> k;
    int pi;
    for(int i = 1; i <= n; i ++ ){
        cin >> pi;
        st.insert(mp(pi, i));
        pos.insert(mp(i, pi));
    }
    bit = 1;
    while(!st.empty()){
        make_a_move();
        if(bit==1)bit=2;
        else bit = 1;
    }
    for(int i = 1; i <= n; i ++ )
        cout << team[i];
    return 0;
}