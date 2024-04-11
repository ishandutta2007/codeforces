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

int n;
int T[310];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        scanf("%d", &T[i]);
    FWD(i,0,n-1){
        if(T[i]){
            printf("P");
            --T[i];
        }
        while(T[i]){
            printf("R");
            if(T[i+1]){
                printf("P");
                --T[i+1];
            }
            printf("L");
            printf("P");
            --T[i];
        }
        printf("R");
    }
        if(T[n-1]){
            printf("P");
            --T[n-1];
        }
        while(T[n-1]){
            printf("L");
            printf("R");
            printf("P");
            --T[n-1];
        }
    printf("\n");
    return 0;
}