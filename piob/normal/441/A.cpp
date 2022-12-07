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
typedef long double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, v;
vector<int> r;

int main(){
    scanf("%d %d", &n, &v);
    FWD(i,0,n){
        int k;
        bool p = 0;
        scanf("%d", &k);
        FWD(j,0,k){
            int a;
            scanf("%d", &a);
            if(a < v) p = 1;
        }
        if(p) r.push_back(i+1);
    }
    printf("%d\n", (int)r.size());
    for(int a : r) printf("%d ", a);
    printf("\n");
    return 0;
}