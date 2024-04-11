#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const int MOD = (int)1e9 + 7;
map<int, int> mm[N];
vector<int> g[N];
multiset<int> has[N];
int mlt[N];

int ans = 1;

int n;

void add(int id, int vl){
    int cnt;
    int low;
    for(auto q : g[vl]){
        cnt = 0;
        while(vl % q == 0) {
            cnt ++ ;
            vl /= q;
        }
        if(mm[id].count(q)) has[q].erase(has[q].find(mm[id][q]));
        mm[id][q] += cnt;
        has[q].insert(mm[id][q]);
        if(has[q].size() == n){
            low = *has[q].begin();
            while(mlt[q] < low){
                ans = (ans * 1ll * q) % MOD;
                mlt[q] ++ ;
            }
        }
    }
}

int main(){
    fastIO;
    for(int i = 2; i < N ;i ++ ){
        if(g[i].empty()){
            for(int j = i ; j < N ; j += i ){
                g[j].push_back(i);
            }
        }
    }
    int q;
    cin >> n >> q;
    int a;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        add(i, a);
    }
    int id;
    for(int i = 1; i <= q; i ++ ){
        cin >> id >> a;
        add(id, a);
        cout << ans << "\n";
    }
    return 0;
}