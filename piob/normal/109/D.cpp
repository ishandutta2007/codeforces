#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PACKS(a) int a; scanf("%d", &a); ++a; while(--a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

int n, m, x, y, k;
int A[100010];
int B[100010];  //gdzie teraz znajduje sie element ktory byl na tej pozycji
int C[100010];  //gdzie ma sie znalezc element ktory byl na tej pozycji
int D[100010];  //gdzie poczatkowo byl element ktory jest tutaj

vector<PII> S;
vector<PII> V;

void move(int a, int b){
    if(a == b)
        return;
    S.push_back(PII(a, b));
    x = D[a];
    y = D[b];
    swap(D[a], D[b]);
    B[x] = b;
    B[y] = a;
}

bool lucky(int x){
    while(x){
        if((x % 10 != 4) && (x % 10 != 7))
            return 0;
        x /= 10;
    }
    return 1;
}

bool sorted(){
    FWD(i,1,n)
        if(A[i] < A[i-1])
            return 0;
    return 1;
}

int main(){
    scanf("%d", &n);
    m = -1;
    FWD(i,0,n){
        scanf("%d", &A[i]);
        if(lucky(A[i]))
            m = i;
        V.push_back(PII(A[i], i));
    }
    if(m == -1){
        if(sorted())
            printf("0\n");
        else
            printf("-1\n");
        return 0;
    }
    sort(V.begin(), V.end());
    FWD(i,0,n){
        B[i] = i;
        C[V[i].y] = i;
        D[i] = i;
    }
    FWD(i,0,n){
        move(m, C[i]);
        m = C[i];
        k = B[i];
        move(B[i], m);
        m = k;
    }
    printf("%d\n", S.size());
    FE(s,S)
        printf("%d %d\n", s->x+1, s->y+1);
    return 0;
}