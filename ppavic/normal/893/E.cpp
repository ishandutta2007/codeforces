#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long int llint;

const int N = 2e6 + 500;
const int RT = 1005;
const int MOD = 1e9 + 7;

vector < int > pr;

llint n,x,y;

void getprime(){
    for(int i = 2;i<RT;i++){
        int ad = 1;
        for(int j = 2;j<i;j++)
            if(i%j==0) ad = 0;
        if(ad) pr.push_back(i);
    }
}

llint fastpot(llint x,llint y){
    llint sol = 1,base = x;
    for(;y;y>>=1){
        if(y&1) sol = (sol * base) % MOD;
        base = (base * base) % MOD;
    }
    return sol;
}

llint fak[N],inv[N],pot[N];

void getfak(){
    fak[0] = 1LL;pot[0] = 1LL;inv[0] = 1LL;
    for(int i = 1;i<N;i++){
        pot[i] = 2 * pot[i-1] % MOD;
        fak[i] = (fak[i-1] * i) % MOD;
        inv[i] = fastpot(fak[i], MOD - 2);
    }
}

llint povrh(int n,int k){
    return fak[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main(){
    getprime();
    getfak();
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d%d",&x,&y);
        vector < int > siz;
        for(int j = 0;j<pr.size();j++){
            if(x%pr[j]) continue;
            int cnt = 0;
            while(!(x%pr[j])){cnt++;x/=pr[j];}
            siz.push_back(cnt);
        }
        if(x != 1) siz.push_back(1);
        llint sol = pot[y-1];
        for(int i = 0;i<siz.size();i++){
            sol = sol * povrh(y + siz[i] - 1, siz[i]) % MOD;
        }
        printf("%d\n",sol);
    }
}