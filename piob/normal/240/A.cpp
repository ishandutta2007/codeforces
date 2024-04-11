#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, m, k, d, fa, nf, bl, a;
bool fav[110];
int mi[110], ma[110];
char buff[12];

bool best(int k){
    FWD(i,0,n){
        if(k == i) continue;
        if(ma[i] > mi[k]) return 0;
    }
    return 1;
}

bool worst(int k){
    int mis = -1;
    FWD(i,0,n){
        if(k == i) continue;
        mis = max(mis, mi[i]);
    }
    if(ma[k] < mis) return 1;
    return 0;
}

int main(){
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d", &m, &k);
    FWD(i,1,m+1) fav[i] = 0;
    FWD(i,0,k){scanf("%d", &d); fav[d] = 1;}
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%s %d", buff, &d);
        fa = 0;
        nf = 0;
        bl = 0;
        FWD(j,0,d){
            scanf("%d", &a);
            if(fav[a]) ++fa;
            if(a != 0 && !fav[a]) ++nf;
            if(a == 0) ++bl;
        }
        mi[i] = max(fa, d-min(m-k, nf+bl));
        ma[i] = min(k, fa+bl);
    }
    FWD(i,0,n){
        if(best(i))
            printf("0\n");
        else{
            if(worst(i))
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}