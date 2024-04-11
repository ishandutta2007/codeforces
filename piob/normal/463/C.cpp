#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
LL M[4010][4010];
LL A[4010];
LL B[4010];
int p, q, r, s, x, y;
LL wp, wn;

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        FWD(j,0,n){
            int a;
            scanf("%d", &a);
            A[i+j] += a;
            B[i-j+n] += a;
            M[i][j] = a;
        }
    wp = -1;
    wn = -1;
    FWD(i,0,2*n)
        FWD(j,0,2*n){
            x = (i+j-n)/2;
            y = i-x;
            if((i&1) != ((j+n)&1))
                continue;
            if(x < 0 || x >= n || y < 0 || y >= n)
                continue;
            if(i&1){
                if(wn < A[i]+B[j]-M[x][y]){
                    wn = A[i]+B[j]-M[x][y];
                    r = x, s = y;
                }
            }else{
                if(wp < A[i]+B[j]-M[x][y]){
                    wp = A[i]+B[j]-M[x][y];
                    p = x, q = y;
                }
            }
        }
    cout << (wp+wn) << " " << (p+1) << " " << (q+1) << " " << (r+1) << " " << (s+1) << endl;
    return 0;
}