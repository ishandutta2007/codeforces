#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
int P[1000010];
int R[1000010];
multiset<int> S[1000010];

int get(int u){
    if(S[u].size() == 1)
        return *S[u].begin();
    return max(*(--S[u].end()), *(--(--S[u].end())) + 1);
}

void update(int u){
    if(R[u] == get(u)) return;
    if(u != 1){ 
        int p = P[u];
        S[p].erase(S[p].find(R[u]));
        R[u] = get(u);
        S[p].insert(R[u]);
        update(p);
    }else
        R[u] = *(--S[u].end());
}

int main(){
    scanf("%d", &n);
    FWD(i,2,n+2){
        scanf("%d", &P[i]);
        R[i] = 1;
        S[P[i]].insert(1);
        update(P[i]);
        printf("%d ", R[1]);
    }
    printf("\n");
    return 0;
}