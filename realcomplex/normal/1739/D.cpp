#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<int> T[N];

int total;
int hh;
int mx[N];

void dfs(int u){
    mx[u] = 0;
    for(auto x : T[u]){
        dfs(x);
        if(mx[x] + 1 == hh){
            if(u != 1) total ++ ;
        }
        else{
            mx[u]=max(mx[u], mx[x] + 1);
        }
    }
}

int k;

bool can(int h){
    hh = h;
    total=0;
    dfs(1);
    return total <= k;
}

void solve(){
    int n;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
    }
    int pi;
    for(int i = 2; i <= n; i ++ ){
        cin >> pi;
        T[pi].push_back(i);
    }
    int li = 1;
    int ri = n;
    int mid;
    while(li < ri){
        mid = (li + ri) / 2;
        if(!can(mid)){
            li = mid + 1;
        }
        else{
            ri = mid;
        }
    }
    cout << li << "\n";

}


int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}