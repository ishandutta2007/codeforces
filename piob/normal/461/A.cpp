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
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
int A[300010];
LL sum, res;

int main(){
    scanf("%d", &n);
    FWD(i,0,n) scanf("%d", &A[i]);
    sort(A, A+n);
    reverse(A, A+n);
    if(n == 1){
        printf("%d\n", A[0]);
        return 0;
    }
    res = A[0] + A[1];
    sum = A[0] + A[1];
    FWD(i,2,n){
        sum += A[i];
        res += sum;
    }
    res += sum;
    cout << res << endl;
    return 0;
}