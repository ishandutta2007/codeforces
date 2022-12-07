#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

char C[14];

bool test(int a, int b){
    FWD(i,0,b){
        bool ok = 1;
        FWD(j,0,a)
            if(C[i+b*j] == 'O')
                ok = 0;
        if(ok)
            return 1;
    }
    return 0;
}

int main(){
    int z; scanf("%d", &z); while(z--){
        scanf("%s", C);
        int c = 0;
        FWD(i,1,13)
            if(12%i==0 && test(i, 12/i))
                ++c;
        printf("%d", c);
        FWD(i,1,13)
            if(12%i==0 && test(i, 12/i))
                printf(" %dx%d", i, 12/i);
        printf("\n");
    }
    return 0;
}