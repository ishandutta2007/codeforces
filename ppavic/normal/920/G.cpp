#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const int N = 1e6 + 500;

vector < int > ras,lcms;

void make_lcms(){
    lcms.clear();
    lcms.push_back(0);
    for(int i = 1;i<(1<<(int)ras.size());i++){
        int lcm = -1;
        for(int j = 0;j<ras.size();j++)
            if((1<<j) & i){
                if(lcm == -1) lcm = ras[j];
                else lcm = (ll)lcm * (ll)ras[j] / (ll)__gcd(lcm, ras[j]);
            }
        lcms.push_back(lcm);
    }
}

int calc(int x){
    int sol = 0;
    for(int i = 1;i<lcms.size();i++){
        if(__builtin_popcount(i)&1) sol += x / lcms[i];
        else                        sol -= x / lcms[i];
    }
    return x - sol;
}

int bin(int lo,int hi,int k){
    int sol = 1e9;
    while(lo <= hi){
        int mid = (lo + hi ) / 2;
        if(calc(mid) >= k)
            sol = min(sol, mid),hi = mid - 1;
        else
            lo = mid + 1;
    }
    return sol;
}

int solve(int x,int y,int k){
    ras.clear();
    for(int i = 2;i*i<=x;i++){
        if(x%i) continue;
        ras.push_back(i);
        while(!(x%i)) x/= i;
    }
    if(x != 1) 
        ras.push_back(x);
    make_lcms();
    return bin(0, 1e7, k + calc(y ));
}

int main(){
    int t;scanf("%d",&t);
    for(int i = 0;i<t;i++){
        int x,p,k;scanf("%d%d%d",&x,&p,&k);
        printf("%d\n",solve(p, x, k));
    }
}