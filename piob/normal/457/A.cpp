#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)

using namespace std;

int n, m;
char A[100010], B[100010];

int comp(){
    BCK(i,n-1,1){
        if(A[i] == B[i]) continue;
        int d = min(A[i], B[i]);
        A[i] -= d;
        B[i] -= d;
        if(A[i] > 1) return 1;
        if(B[i] > 1) return -1;
        if(A[i] && (B[i-1] <= A[i-1])) return 1;
        if(B[i] && (A[i-1] <= B[i-1])) return -1;
        if(A[i]) ++A[i-1], ++A[i-2];
        if(B[i]) ++B[i-1], ++B[i-2];
    }
    long double r = (A[1]-B[1]) * (sqrt(5)+1)/2 + (A[0]-B[0]);
    if(r > 1e-9)
        return 1;
    if(-r > 1e-9)
        return -1;
    return 0;
}

int main(){
    scanf("%s %s", A, B);
    n = strlen(A);
    m = strlen(B);
    reverse(A, A+n);
    reverse(B, B+m);
    while(n<m) A[n++] = '0';
    while(m<n) B[m++] = '0';
    FWD(i,0,n) A[i] -= '0', B[i] -= '0';
    n += 4;
    int w = comp();
    if(w > 0) printf(">\n");
    if(w == 0) printf("=\n");
    if(w < 0) printf("<\n");
    return 0;
}