#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int llint;

const int N = 55;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int red[N],stup[N];
llint pot[N];

void pre(){
  pot[0] = 1LL;
  for(int i = 1;i<N;i++){
    pot[i] = pot[i - 1] * 2LL;
  }
}

int n,m,x;

int main(){
  pre();
  scanf("%d%d",&n,&m);
  for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
      scanf("%d",&x);
      if(x){
        red[i]++;
        stup[j]++;
      }
    }
  }
  llint sol = 0;
  for(int i = 0;i<n;i++){
    sol += pot[red[i]] - 1LL + pot[m - red[i]] - 1LL;
  }
  for(int i = 0;i<m;i++){
    sol += pot[stup[i]] - 1LL + + pot[n - stup[i]] - 1LL;
  }
  sol -= (llint)n * (llint)m;
  printf("%I64d\n",sol);
}