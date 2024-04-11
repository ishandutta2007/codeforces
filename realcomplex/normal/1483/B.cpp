#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;

set<int> alive;
set<int> bad;
int A[N];

int get_nex(int id){
    auto it = alive.upper_bound(id);
    if(it == alive.end())
        return *alive.begin();
    return *it;
}

int del(int id){
    auto pv = alive.lower_bound(id);
    if(pv == alive.begin()){
        pv = alive.end();
        pv -- ;
    }
    else{
        pv -- ;
    }
    alive.erase(id);
    bad.erase(id);
    int chk = get_nex(id);
    if(bad.count(chk)){
        bad.erase(chk);
    }
    if(__gcd(A[chk], A[*pv]) == 1){
        bad.insert(chk);
    }
    return get_nex(chk);

}


void solve(){
    int n;
    cin >> n;
    alive.clear();
    bad.clear();
    for(int i = 0; i < n; i ++ ){
        cin >> A[i];
        alive.insert(i);
    }
    int id;
    for(int i = 0 ; i < n; i ++ ){
        if(__gcd(A[i], A[(i - 1 + n) % n]) == 1){
            bad.insert(i);
        }
    }
    int go = 1;
    vector<int> outp;
    while(alive.size() > 1 && !bad.empty()){
        auto it = bad.lower_bound(go);
        if(it == bad.end())
            it = bad.begin();
        outp.push_back(*it);
        go = del(*it);
    }
    if(alive.size() == 1 && A[*alive.begin()] == 1){
        outp.push_back(*alive.begin());
        alive.erase(alive.begin());
    }
    cout << outp.size() << " ";
    for(auto x : outp)
        cout << x + 1 << " ";
    cout << "\n";
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