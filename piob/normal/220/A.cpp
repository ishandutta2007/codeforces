#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define LL long long

using namespace std;

int n;
int T[100010];
int S[100010];
vector<int> V;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &T[i]);
        S[i] = T[i];
    }
    sort(S, S+n);
    FWD(i,0,n)
        if(S[i] != T[i])
            V.push_back(i);
    if(V.size() != 2 && V.size() != 0){
        printf("NO\n");
    }else{
        if(V.size() == 0 || (S[V[0]] == T[V[1]] && S[V[1]] == T[V[0]]))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}