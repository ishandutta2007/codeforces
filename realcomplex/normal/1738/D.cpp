#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int b[N];
int pre[N];
int suf[N];
vector<int> id[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i <= n + 1; i ++ ){
        pre[i] = n + 1;
        suf[i] = 0;
        id[i].clear();
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> b[i];
        id[b[i]].push_back(i);
        pre[i] = min(pre[i-1], b[i]);
    }
    for(int i = n; i >= 1; i -- ){
        suf[i] = max(suf[i+1], b[i]);
    }
    int yes = -1;
    for(int k = 0 ; k <= n; k ++ ) {
        if(pre[k] > k && suf[k + 1] <= k){
            yes = k;
        }
    }
    vector<int> seq;
    for(int i = 1; i <= n; i ++ ){
        if(b[i] == n + 1 || b[i] == 0){
            seq.push_back(i);
        }
    }
    vector<int> soln;
    int send;
    while(!seq.empty()){
        send = -1;
        for(auto v : seq){
            if(!id[v].empty()){
                send = v;
            }
        }
        for(auto v : seq){
            if(v != send) soln.push_back(v);
        }
        if(send == -1){
            seq.clear();
        }
        else{
            soln.push_back(send);
            seq = id[send];
        }
    }
    cout << yes << "\n";
    for(auto x : soln){
        cout << x << " ";
    }
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