#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
vector<PII> V;
double md;

#define sq(a) ((a)*(a))
double dist(int a, int b){
    return sqrt(sq(V[a].x-V[b].x)+sq(V[a].y-V[b].y));
}

int main(){
    scanf("%d %d", &n, &m);
    V.push_back(PII(0,0));
    FWD(i,0,4)
        FWD(j,0,4)
            if(i <= n && j <= m)
                V.push_back(PII(i,j));
    FWD(i,0,4)
        FWD(j,0,4)
            if(i <= n && j <= m)
                V.push_back(PII(n-i, m-j));
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    n = (int)V.size();
    FWD(a,0,n)
        FWD(b,0,n)
            if(a!=b)
                FWD(c,0,n)
                    if(a!=c&&b!=c)
                        FWD(d,0,n)
                            if(a!=d&&b!=d&&c!=d)
                                md = max(md, dist(a,b)+dist(b,c)+dist(c,d));
    FWD(a,0,n)
        FWD(b,0,n)
            if(a!=b)
                FWD(c,0,n)
                    if(a!=c&&b!=c)
                        FWD(d,0,n)
                            if(a!=d&&b!=d&&c!=d)
                                if(abs(md-dist(a,b)-dist(b,c)-dist(c,d)) < 1e-9){
                                    printf("%d %d\n", V[a].x, V[a].y);
                                    printf("%d %d\n", V[b].x, V[b].y);
                                    printf("%d %d\n", V[c].x, V[c].y);
                                    printf("%d %d\n", V[d].x, V[d].y);
                                    return 0;
                                }
    return 0;
}