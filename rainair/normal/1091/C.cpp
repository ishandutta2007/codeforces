#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
std::vector<int> S;
signed main(){
    int N;scanf("%I64d",&N);
    int q = std::sqrt((double)N);
    FOR(i,1,q){
        if(!(N%i)){
            S.push_back(i);
            if(i*i != N) S.push_back(N/i);
        }
    }
    std::vector<int> A;
    FOR(i,0,(int)S.size()-1){
        int step = S[i],ans=0;
        int len = N/step;
        // DEBUG(step);
        int a1 = 1,an = (N/step)-1;
        A.push_back(len*a1+(len*(len-1))/2*step);
    }
    std::sort(A.begin(),A.end());
    FOR(i,0,(int)A.size()-1){
        printf("%I64d ",A[i]);
    }
    puts("");
    return 0;
}