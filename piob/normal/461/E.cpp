#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

struct node{
    node *next[4], *suf;
    int dist[4];
    int vis;
    int len;
    node(int _len=0, node *_suf=NULL, node **_next=NULL) : suf(_suf), len(_len) {
        vis = 0;
        if(!_next) REP(i,4) next[i] = NULL;
        else REP(i,4) next[i] = _next[i];
    }
};

node *root, *last;
LL n;

void add(int c){
    node *p = last, *np = new node(last->len+1);
    for(;p && !p->next[c];p=p->suf) p->next[c] = np;
    if(!p) np->suf = root;
    else {
        node *q = p->next[c];
        if(p->len+1 == q->len) np->suf = q;
        else {
            node *nq = new node(p->len+1, q->suf, q->next);
            q->suf = np->suf = nq;
            for(;p && p->next[c] == q;p=p->suf) p->next[c] = nq;
        }
    }
    last = np;
}

void calc(node* u){
    if(u->vis) return;
    u->vis = 1;
    FWD(i,0,4) if(u->next[i]) calc(u->next[i]);
    FWD(i,0,4) u->dist[i] = u->next[i]?1000000:1;
    FWD(i,0,4)
        if(u->next[i])
            FWD(j,0,4)
                    u->dist[j] = min(u->dist[j], u->next[i]->dist[j]+1);
}

LL M[83][4][4];

void mult(int a, int b, int c){
    FWD(i,0,4)
        FWD(j,0,4)
            M[c][i][j] = n+3;
    FWD(i,0,4)
        FWD(j,0,4)
            FWD(k,0,4)
                M[c][i][k] = min(M[c][i][k], M[a][i][j] + M[b][j][k]);
}

void mov(int a, int b){
    FWD(i,0,4)
        FWD(j,0,4)
            M[b][i][j] = M[a][i][j];
}

bool sm(int a){
    FWD(i,0,4)
        FWD(j,0,4)
            if(M[a][i][j] < n)
                return 1;
    return 0;
}

int main(){
    root = last = new node();
    cin >> n;
    string T;
    cin >> T;
    FWD(i,0,(int)T.size()) add(T[i]-'A');
    calc(root);
    FWD(i,0,4){
        FWD(j,0,4){
            M[0][i][j] = root->next[i]->dist[j];
        }
    }
    FWD(p,1,62)
        mult(p-1, p-1, p);
    FWD(i,0,4)
        FWD(j,0,4)
            M[80][i][j] = 0;
    LL r = 1;
    BCK(i,61,-1){
        mult(80,i,81);
        if(sm(81)){
            r += (1LL << i);
            mov(81, 80);
        }
    }
    cout << r << endl;
    return 0;
}