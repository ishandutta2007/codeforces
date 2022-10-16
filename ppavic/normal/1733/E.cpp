#include <cstdio>
#include <vector>
#include <cstring>

#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 125;

ll cnt[N][N];

void count(ll T){
memset(cnt,0,sizeof(cnt));
cnt[0][0] = T;
for(int i = 0;i<=120;i++)
for(int j = 0;j <= 120;j++){
cnt[i + 1][j] += cnt[i][j] / 2;
cnt[i][j + 1] += (cnt[i][j] + 1) / 2;
}
}

void solve(){
ll x,y,t;
scanf("%lld%lld%lld", &t,&x,&y);
t -= x + y;t++;
if(t < 1){
printf("NO\n"); return;
}
count(t); ll a = cnt[x][y];
count(t-1); ll b = cnt[x][y];
printf(a != b ? "YES\n":"NO\n");
}

int main(){
int T; scanf("%d",&T);
for(;T--;) solve();

}