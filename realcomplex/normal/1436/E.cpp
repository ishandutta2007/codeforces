#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int tree[N*2];
int lim;

void upd(int idx, int v){
    idx += lim;
    tree[idx]=v;
    idx /= 2;
    while(idx > 0){
        tree[idx]=min(tree[idx*2],tree[idx*2+1]);
        idx /= 2;
    }
}

int qry(int l, int r){
    l += lim;
    r += lim;
    int ans = (int)1e9;
    while(l <= r){
        if(l % 2 == 1) ans = min(ans, tree[l ++ ]);
        if(r % 2 == 0) ans = min(ans, tree[r -- ]);
        l /= 2;
        r /= 2;
    }
    return ans;
}

bool is[N];
int las[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    lim=n+1;
    int a;
    for(int i = 1; i <= n; i ++ ){
        las[i]=0;
        upd(i,0);
    }
    int lf, rf;
    bool has = false;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        if(a > 1) has = true;
        if(a > 1 && i-1>=las[a]+1){
            lf = las[a] + 1;
            rf = i - 1;
            if(qry(1,a-1) >= lf)
                is[a]=true;
        }
        las[a]=i;
        upd(a,i);
    }
    if(!has){
        cout << 1 << "\n";
        return 0;
    }
    for(int i = 2; i <= n + 1 ; i ++ ){
        if(las[i] < n){
            if(qry(1,i-1) >= las[i]+1)
                is[i]=true;
        }
    }
    for(int i = 2; i <= n + 2; i ++ ){
        if(!is[i]){
            cout << i << " ";
            return 0;
        }
    }
    return 0;
}