#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define LL long long

using namespace std;

int n;
int A[100010];
int B[100010];
int P[100010];
int in, de;
multiset<int> inc;
multiset<int> dev;

int main(){
    scanf("%d", &n);
    FWD(i,1,n+1)
        scanf("%d", &A[i]);
    FWD(i,1,n+1)
        P[A[i]] = i;
    FWD(i,1,n+1)
        scanf("%d", &B[i]);
    in = de = 0;
    FWD(i,1,n+1){
        if(P[B[i]] < i)
            dev.insert(i-P[B[i]]);
        else
            inc.insert(P[B[i]] - i);
    }
   //         FE(a,inc)
   //         printf("ros: %d\n", *a);
   //     FE(a,dev)
   //         printf("mal: %d\n", *a);

    FWD(i,1,n+1){
        //printf("%d + %d lub %d + %d\n", *inc.begin(), in, *dev.begin(), de);
        if(inc.empty()) printf("%d\n", *dev.begin() + de);
        if(dev.empty()) printf("%d\n", *inc.begin() + in);
        if(!inc.empty() && !dev.empty()) printf("%d\n", min(*inc.begin() + in, *dev.begin() + de));
        inc.erase(inc.find(P[B[i]] - 1 - in));
        //printf("%d %d usuwam %d\n", in, de, P[B[i]] - 1);
        ++in;
        --de;
        dev.insert(n-P[B[i]]-de);
        //printf("%d %d dodaje %d\n", in, de, n - P[B[i]]);
        while(*dev.begin() == -de){
            //printf("przenosze %d\n", -de);
            inc.insert(-in);
            dev.erase(dev.begin());
        }
       // FE(a,inc)
       //     printf("ros: %d\n", *a);
       // FE(a,dev)
       //     printf("mal: %d\n", *a);
    }
    return 0;
}