#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
    int len;
    int pre[2][2];
    int suf[2][2];
    int sol[2];
    int rev;
};

const int N = (int)5e5 + 10;

Node T[N * 4 + 512];
int st[N];

Node unite(Node A, Node B){
    Node res;
    res.rev = false;
    res.len = A.len + B.len;
    for(int i = 0 ; i < 2; i ++ ){
        for(int j = 0 ; j < 2; j ++ ){
            res.pre[i][j] = A.pre[i][j];
            res.suf[i][j] = B.suf[i][j];
        }
    }
    for(int i = 0 ; i < 2; i ++ ){
        res.sol[i] = max(A.sol[i], B.sol[i]);
    }
    int dis;
    for(int i = 0 ; i < 2; i ++ ){
        for(int j = 0 ; j < 2; j ++ ){
            for(int p = 0 ; p < 2; p ++ ){
                for(int q = 0; q < 2; q ++ ){
                    dis = (i^j) + (j^p) + (p^q);
                    if(dis > 1) continue;
                    res.sol[i] = max(res.sol[i], A.suf[i][j] + B.pre[p][q]);
                    if(A.pre[i][j] == A.len)
                        res.pre[i][q] = max(res.pre[i][q], A.pre[i][j] + B.pre[p][q]);
                    if(B.suf[p][q] == B.len)
                        res.suf[i][q] = max(res.suf[i][q], A.suf[i][j] + B.suf[p][q]);
                }
            }
        }
    }
    for(int i = 0 ; i < 2; i ++ ){
        for(int j = 0 ; j < 2; j ++ ){
            res.sol[i] = max(res.sol[i], res.pre[i][j]);
            res.sol[i] = max(res.sol[i], res.suf[i][j]);
        }
    }
    int mx = max({res.pre[0][0], res.pre[1][1], res.suf[0][0], res.suf[1][1]});
    for(int i = 0 ; i < 2; i ++ )
        res.sol[i] = max(res.sol[i], mx);
    return res;
}

void build(int node, int cl, int cr){
    if(cl == cr){
        T[node].len = 1;
        T[node].pre[st[cl]][st[cl]] = 1;
        T[node].suf[st[cl]][st[cl]] = 1;
        T[node].sol[0] = T[node].sol[1] = 1;
        return ;
    }
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
    T[node] = unite(T[node * 2], T[node * 2 + 1]);
}

void push(int node, int cl, int cr){
    if(T[node].rev){
        if(cl != cr){
            T[node*2].rev ^= 1;
            T[node*2+1].rev ^= 1;
        }
        for(int i = 0 ; i < 2; i ++ ){
            swap(T[node].pre[0][i], T[node].pre[1][1-i]);
            swap(T[node].suf[0][i], T[node].suf[1][1-i]);
        }
        swap(T[node].sol[0], T[node].sol[1]);
        T[node].rev=false;
    }
}

Node sha;
bool kek;

void update(int node, int cl, int cr, int tl, int tr){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return ;
    if(cl >= tl && cr <= tr){
        T[node].rev=true;
        push(node,cl,cr);
        if(kek){
            sha=T[node];
            kek=false;
        }
        else{
            sha=unite(sha,T[node]);
        }
        return;
    }
    int mid = (cl + cr) / 2;
    update(node * 2, cl, mid, tl, tr);
    update(node * 2 + 1, mid + 1, cr, tl, tr);
    T[node] = unite(T[node*2], T[node*2+1]);
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    char ut;
    for(int i = 1; i <=n ; i ++ ){
        cin >> ut;
        if(ut == '>') st[i] = 0;
        else st[i] = 1;
    }
    build(1, 1, n);
    int li, ri;
    for(int i = 1; i <= q; i ++ ){
        cin >> li >> ri;
        kek=true;
        update(1, 1, n, li, ri);
        cout << sha.sol[0] << "\n";
    }
    return 0;
}