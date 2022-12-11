#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)4e5 + 10;
int li[N], ri[N], cl[N];

struct node{
    int val;
    int lazy;
};

node tre[2][N * 4 + 512];

void push(int bit, int node, int cl, int cr){
    tre[bit][node].val += tre[bit][node].lazy;
    if(cl != cr){
        tre[bit][node*2].lazy += tre[bit][node].lazy;
        tre[bit][node*2+1].lazy += tre[bit][node].lazy;
    }
    tre[bit][node].lazy = 0;
}

void upd(int bit, int node, int cl, int cr, int tl, int tr, int v){
    push(bit, node, cl, cr);
    if(cr < tl || cl > tr)
        return;
    if(cl >= tl && cr <= tr){
        tre[bit][node].lazy = v;
        push(bit, node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    upd(bit, node * 2, cl, mid, tl, tr, v);
    upd(bit, node * 2 + 1, mid + 1, cr, tl, tr, v);
    tre[bit][node].val = max(tre[bit][node*2].val, tre[bit][node*2+1].val);
}

vector<int> P[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> cors = {0};
    for(int i = 1; i <= n; i ++ ){
        cin >> li[i] >> ri[i] >> cl[i];
        cors.push_back(li[i]);
        cors.push_back(ri[i]);
        cl[i]--;
    }
    sort(cors.begin(), cors.end());
    cors.resize(unique(cors.begin(), cors.end()) - cors.begin());
    int len = cors.size();
    for(int i = 1; i <= n; i ++ ){
        li[i]=lower_bound(cors.begin(),cors.end(),li[i]) - cors.begin();
        ri[i]=lower_bound(cors.begin(),cors.end(),ri[i]) - cors.begin();
        P[ri[i]].push_back(i);
    }
    int sol;
    int answ = 0;
    for(int i = 1; i < len; i ++ ){
        for(auto x : P[i]){
            upd(cl[x]^1, 1, 0, len - 1, 0, li[x]-1, +1);
        }

        for(int j = 0 ; j < 2; j ++ ){
            sol = tre[!j][1].val;
            answ = max(answ, sol);
            upd(j, 1, 0, len - 1, i, i, sol);
        }

    }
    cout << answ << "\n";
    return 0;
}