#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)

using namespace std;

int n, m;
int A[100010];
int B[100010];
int D[200010];
vector<int> R;

int test(int c){
    int r = 0;
    int a = 0;
    int b = 0;
    while(a < n || b < m){
        //printf("    %d %d\n", a, b);
        while(A[a] == c || B[b] == c){
            if(A[a] == c) ++a; else ++b;
        }
        ++r;
        c = 1-c;
    }
    if(c != 0) --r;
    //printf("tested\n");
    return r;
}

void make(int c){
    int a = 0;
    int b = 0;
    while(a < n || b < m){
        while(A[a] == c || B[b] == c){
            if(A[a] == c){
                ++a;
                printf("%d ", a);
            }else{
                ++b;
                printf("%d ", b+n);
            }
        }
        R.push_back(a+b);
        c = 1-c;
    }
    if(c != 0) R.pop_back();
}

int main(){
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    FWD(i,0,n) scanf("%d", &A[i]);
    scanf("%d", &m);
    FWD(i,0,m) scanf("%d", &B[i]);
    A[n] = B[m] = 2;
    if(test(0) < test(1)){
        make(0);
    }else
        make(1);
    printf("\n%d\n", R.size());
    FWD(i,0,R.size()) printf("%d ", R[i]);
    printf("\n");
    return 0;
}