#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, x;
map<int, vector<int> > M;
map<int, int> C;
int P[200100];
int D[200100];
int R[200100];
LL m, r;

void mark(int x, int y){
    int t = 2;
    while(x > 1){
        P[D[x]] += y;
        x = R[x];
    }
}

void cnt(vector<int> &V){
    C.clear();
    FWD(i,0,(int)V.size()) ++C[V[i]];
    FWD(i,2,(int)(V.size())+1) mark(i,1);
    for(auto &c : C)
        FWD(i,2,c.y+1)
            mark(i, -1);
}

int main(){
    for(int i = 2; i*i < 200100; ++i)
        if(D[i] == 0){
            D[i] = i;
            R[i] = 1;
            for(int j = i*i; j < 200100; j += i){
                D[j] = i;
                R[j] = j/i;
            }
        }
    FWD(i,2,200100) if(D[i] == 0){D[i] = i, R[i] = 1;}
    cin >> n;
    FWD(i,0,n){
        cin >> x;
        M[x].push_back(i);
    }
    FWD(i,0,n){
        cin >> x;
        M[x].push_back(i);
    }
    cin >> m;
    for(auto &e : M) cnt(e.y);
    r = 1;
    FWD(i,0,2*n+3) while(P[i]--) r = (r*i)%m;
    cout << r << endl;
    return 0;
}