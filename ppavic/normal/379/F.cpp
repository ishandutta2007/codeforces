#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e6 + 500;

// Ubit u se preventivno

int q,m1,m2,c1,c2;
int dub[N],x,c = 4;
int par[N][21];

void sett(int x){
  for(int i = 1;i<=20;i++)
    par[x][i] = par[par[x][i-1]][i-1];
}

int lca(int y,int x){
  for(int i = 20;i>=0;i--){
    if(dub[x] - dub[y] >= (1 << i))
      x = par[x][i];
  }
  if(x == y) return x;
  for(int i = 20;i>=0;i--){
    if(par[x][i] != par[y][i]){
      x = par[x][i];
      y = par[y][i];
    }
  }
  return par[x][0];
}

int main(){
  scanf("%d",&q);
  int sol = 2;
  dub[2] = 1;dub[3] = 1;dub[4] = 1;
  m1 = 1;c1 = 2;
  par[2][0] = 1;par[3][0] = 1;par[4][0] = 1;
  for(int i = 0;i<q;i++){
    scanf("%d",&x);
    par[c+1][0] = x;par[c+2][0] = x;
    sett(c+1);sett(c+2);
    dub[c+1] = dub[x] + 1;dub[c+2] = dub[x] + 1;
    if(dub[c + 1] > m1){
      m1 = dub[c + 1];sol++;
      c1 = c + 1;
    }
    if(dub[c + 2] + dub[c1] - 2 * dub[lca(c+2,c1)] > sol){
      sol = dub[c+2] + dub[c1] - 2 * dub[lca(c+2,c1)];
    }
    c += 2;
    printf("%d\n",sol);
  }

}