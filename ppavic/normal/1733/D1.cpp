#include <cstdio>

#include<algorithm>
using namespace std;

const int N = 2e5 + 500;
char A[N];

void solve(){
int n,x,y;scanf(" %d%d%d", &n,&x,&y);

for(int i = 0;i<n;i++) scanf(" %c", A+i);
int cnt = 0, sus = 0;
for(int i = 0;i<n;i++){
char x; scanf(" %c", &x); if(A[i] != x){
A[i] = 'x';
cnt++; sus += i && A[i - 1] == 'x';
}
}
if(cnt&1){
printf("-1\n"); return;
}
if(cnt == 2 && sus){
printf("%d\n", min(2 * y, x));return;}
printf("%lld\n", (long long)(cnt / 2) * y);
}
int main(){
int T; scanf("%d", &T);
for(;T--;) solve();

}