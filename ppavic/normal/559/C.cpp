#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair < int ,int > pii;
typedef long long int llint;

const int N = 2005;
const int M = 2e5 + 500;
const int MOD = 1e9 + 7;

vector < pii > v;

llint dp[N],fak[M];
llint h,w,n,x,y;

inline llint sub(llint A,llint B){
    if(A - B  < 0) return A - B + MOD;
    return A - B;
}

inline llint precomp(){
    fak[0] = 1;
    for(int i = 1;i<M;i++)
        fak[i] = (i * fak[i - 1]) % MOD;
}

inline llint inv(llint bs){
    llint kvd = bs,eks = MOD - 2,sol = 1;
    while(eks > 0){
        if(eks & 1){
            sol = (sol * kvd) % MOD;
        }
        kvd = (kvd * kvd) % MOD;
        eks /= 2;
    }
    return sol;
}

inline llint divv(llint A,llint B){
    return  (A * inv(B)) % MOD;
}

inline llint choose(llint N,llint K){
    return divv(fak[N], (fak[K] * fak[N - K]) % MOD);
}


int main(){
    precomp();
    scanf("%I64d%I64d%I64d",&h,&w,&n);
    for(int i = 0;i<n;i++){
        scanf("%I64d%I64d",&x,&y);x--;y--;
        v.push_back(make_pair(x,y));
    }
    v.push_back(make_pair(h-1,w-1));
    sort(v.begin(),v.end());
    for(int i = 0;i<=n;i++){
        dp[i] = choose(v[i].first+v[i].second,v[i].first);

        for(int j = 0;j<i;j++){
            if(v[j].first > v[i].first || v[j].second > v[i].second) continue;
            dp[i] = sub(dp[i],dp[j] * choose(v[i].first+v[i].second-v[j].first-v[j].second,v[i].first - v[j].first)  % MOD);

        }
    }
    printf("%d\n",dp[n]);

}