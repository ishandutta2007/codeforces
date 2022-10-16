#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long int llint;

const int MOD = 1e9+7;
const int MOD2 = 1e9+9;
const int base = 982451653;
const int base2 = 982451707;
const int N = 5*1e5+500;
const int M = 1e6+500;

map <pair <pair <int,int> ,pair <int,int> > ,int> cnt;

vector <int> g;
int n,m,c;
llint perm[M],pot1[N],pot2[N];
int jot[N];
llint hsh11[M];
llint hsh21[M];
llint hsh12[M];
llint hsh22[M];


void preload(){
    perm[0] = 1;pot1[0] = 1;pot2[0] = 1;
    for(int i = 1;i<M;i++) perm[i] = (perm[i-1] * i) % MOD;
    for(int i = 1;i<N;i++) pot1[i] = (pot1[i-1] * base) % MOD;
    for(int i = 1;i<N;i++) pot2[i] = (pot2[i-1] * base2) % MOD;
}


int main(){
    scanf("%d %d",&n,&m);
    preload();
    for(int i = 0;i<n;i++) {
        int z;
        scanf("%d",&z);
        for(int j = 0;j<z;j++){
            int cnt;scanf("%d",&cnt);
            g.push_back(cnt);
        }
        sort(g.begin(),g.end());
        for(int j = 0;j<g.size();){
            int oldi = j;
            int c = 0;
            while(j < g.size() && g[j] == g[oldi]){
                j++;c++;
            }
            hsh11[g[oldi]] += (c * pot1[i]) %MOD;
            hsh12[g[oldi]] +=  (c * pot1[i]) %MOD2;
            hsh21[g[oldi]] += (c * pot2[i]) %MOD;
            hsh22[g[oldi]] +=  (c * pot2[i]) %MOD2;
        }
        g.clear();
    }
    llint sol = 1;
    for(int i = 1;i<=m;i++){
        cnt[make_pair(make_pair(hsh11[i],hsh12[i]),make_pair(hsh21[i],hsh22[i]))]++;
    }
    for(map <pair <pair <int,int> ,pair <int,int> > ,int>::iterator it = cnt.begin();it!=cnt.end();it++){
        sol *= perm[it->second];
        sol %= MOD;
    }
    printf("%d\n",sol);
}