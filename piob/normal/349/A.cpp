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

int n, a, b;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        int x;
        scanf("%d", &x);
        if(x == 25){
            ++a;
        }else if(x == 50){
            if(!a){
                printf("NO\n");
                return 0;
            }
            ++b;
            --a;
        }else{
            if(b){
                if(!a){
                    printf("NO\n");
                    return 0;
                }
                --b;
                --a;
            }else{
                if(a < 3){
                    printf("NO\n");
                    return 0;
                }
                a -= 3;
            }
        }
    }
    printf("YES\n");
    return 0;
}