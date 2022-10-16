#include <cstdio>

#include<algorithm>
using namespace std;

const int N = 205;

int n,x,y;

void solve(){
scanf("%d%d%d", &n, &x, &y);
if(x == -1 || y == -1){
for(int i = 1;i< n;i++) printf("%d ", i + 1);
printf("\n");return;}
if((!x || !y) && (x + y) && (n-1) % (x + y) == 0){
for(int j = 0;j < (n-1)/ (x + y);j++){

for(int i = 0;i < x + y;i++) printf("%d ", j * (x + y) + 1 + !!j);

}
printf("\n");return;
}printf("-1\n");
}
int main(){
int T; scanf("%d", &T);
for(;T--;) solve();

}