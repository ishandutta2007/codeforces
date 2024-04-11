#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
int f[N];
vector<int> pos[2];
int sz[N];

int find_next(int i, int bit){
    int low = upper_bound(pos[bit].begin(), pos[bit].end(), i) - pos[bit].begin();
    return pos[bit][low];
}

vector<int> dd[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    char q;
    for(int i = 1 ; i <= n; i ++ ){
        cin >> q;
        if(q == '?') f[i] = 3;
        else{
            f[i] = q - '0';
            pos[f[i]].push_back(i);
        }
    }
    pos[0].push_back(n + 1);
    pos[1].push_back(n + 1);
    int np;
    set<int> dels;
    for(int i = 1; i <= n; i ++ ){
        if(f[i] == 3){
            np = max(find_next(i, 0), find_next(i,1));
        }
        else{
            np = find_next(i, (f[i]^1));
        }
        sz[i] = np - i;
        dd[sz[i]].push_back(i);
        dels.insert(i);
    }
    int y;
    int cur;
    int answ = 0;
    for(int i = 1; i <= n; i ++ ){
        y = 1;
        answ = 0;
        while(1){
            auto nx = dels.lower_bound(y);
            if(nx == dels.end()) break;
            y = *nx;
            cur = sz[y];
            while(cur >= i){
                cur -= i;
                answ ++ ;
                y += i;
            }
        }
        cout << answ << " ";
        for(auto x : dd[i]){
            dels.erase(x);
        }
    }
    return 0;
}