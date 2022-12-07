#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;

int main(){
    scanf("%d %d", &n, &m);
    if(m&1){
        int p = (m+1)/2;
        FWD(i,0,n){
            printf("%d\n", p);
            if(p == m)
                p = (m+1)/2;
            else if(p == (m+1)/2)
                --p;
            else if(p < (m+1)/2)
                p = m+1-p;
            else
                p = m-p;
        }
    }else{
        int p = m/2;
        FWD(i,0,n){
            printf("%d\n", p);
            if(p == m)
                p = m/2;
            else if(2*p < m+1)
                p = m+1-p;
            else
                p = m-p;
        }
    }
    return 0;
}