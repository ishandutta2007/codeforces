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

int a, b, p, q, r;

int main(){
    scanf("%d %d", &a, &b);
    FWD(i,1,7){
        int x = abs(i-a);
        int y = abs(i-b);
        if(x < y)
            ++p;
        else if(x==y)
            ++q;
        else
            ++r;
    }
    printf("%d %d %d\n", p, q, r);
    return 0;
}