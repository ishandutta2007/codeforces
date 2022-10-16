#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define vi vector<int>

using namespace std;

const int nax = (1 << 19);
int a[nax];
int n, k;

struct node{
    node * lft, * rgt;
    int prefix, len;
    vector<int> mini, maxi, ans, numbers;
};

node * root;

void dfs(node * cur){
    if(cur->len == k){
        cur->mini.resize(1); cur->maxi.resize(1); cur->ans.resize(1);
        cur->mini[0] = 0;
        cur->maxi[0] = 0;
        cur->ans[0] = 1e9;
        return;
    }
    if(cur->len > k) return;
    if(cur->numbers.empty()) return;
    cur->rgt = new node;
    cur->lft = new node;
    for(int x : cur->numbers){
        int v = (x & (1 << (k - cur->len - 1)));
        if(v){
            cur->rgt->numbers.pb(x ^ v);
        }
        else cur->lft->numbers.pb(x ^ v);
    }
    cur->lft->len = cur->rgt->len = cur->len + 1;
    cur->lft->prefix = cur->prefix * 2;
    cur->rgt->prefix = cur->prefix * 2 + 1;
    dfs(cur->lft);
    dfs(cur->rgt);
    int sz = (1 << (k - cur->len));
    cur->mini.resize(sz, 1e9); cur->maxi.resize(sz, -1e9); cur->ans.resize(sz, 1e9);
    if(cur->lft->numbers.size()){
        for(int i=0;i<sz/2;i++){
            cur->ans[i] = min(cur->ans[i], cur->lft->ans[i]);
            cur->ans[i + sz / 2] = min(cur->ans[i + sz / 2], cur->lft->ans[i]);
        }
    }

    if(cur->rgt->numbers.size()){
        for(int i=0;i<sz/2;i++){
            cur->ans[i] = min(cur->ans[i], cur->rgt->ans[i]);
            cur->ans[i + sz / 2] = min(cur->ans[i + sz / 2], cur->rgt->ans[i]);
        }
    }
    int ful = (sz/2-1);
    for(int i=0;i<sz;i++){
        int B = (i & (sz / 2));
        if(cur->lft->numbers.size()){
            cur->mini[i] = min(cur->mini[i], B + cur->lft->mini[i&ful]);
            cur->maxi[i] = max(cur->maxi[i], B + cur->lft->maxi[i&ful]);
        }
        if(cur->rgt->numbers.size()){
            cur->mini[i] = min(cur->mini[i], sz / 2 - B + cur->rgt->mini[i&ful]);
            cur->maxi[i] = max(cur->maxi[i], sz / 2 - B + cur->rgt->maxi[i&ful]);
        }
        if(cur->lft->numbers.size() && cur->rgt->numbers.size()){
            if(B == 0) cur->ans[i] = min(cur->ans[i], cur->rgt->mini[i&ful] + sz / 2 - cur->lft->maxi[i&ful]);
            else cur->ans[i] = min(cur->ans[i], cur->lft->mini[i&ful] + sz / 2 - cur->rgt->maxi[i&ful]);
        }
    }
}

void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    root = new node;
    root->prefix = 0;
    root->len = 0;
    root->numbers.resize(n);
    for(int i=0;i<n;i++) root->numbers[i] = a[i];
    dfs(root);
    for(int i=0;i<(1<<k);i++) cout<<root->ans[i]<<" ";



}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}