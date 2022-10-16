#include <cstdio>
#include <bitset>
#include <algorithm>

using namespace std;

const int N = 7001;
const int M = 1e5 + 500;

bitset < N > pos[N];
bitset < N > a[M], nam[N];
int dob[N], n, q;

bool dobar(int x){
    for(int i = 2;i * i <= x;i++){
        if(x % i) continue;
        x /= i;
        if(!(x % i)) return 0;
    }
    return 1;
}


int main(){
    for(int i = 1;i<N;i++) dob[i] = dobar(i);
    for(int i = 1;i<N;i++){
        for(int j = i;j<N;j += i){
            pos[i][j] = dob[j / i];
            nam[j][i] = 1;
        }
    }
    scanf("%d%d", &n, &q);
    for(int i = 0;i<q;i++){
        int ty;scanf("%d", &ty);
        if(ty == 1){
            int x, v;scanf("%d%d", &x, &v);
            a[x] = nam[v];
        }
        else if(ty == 2){
            int x, y, z;scanf("%d%d%d", &x, &y, &z);
            a[x] = a[y] ^ a[z];
        }
        else if(ty == 3){
            int x, y, z;scanf("%d%d%d", &x, &y, &z);
            a[x] = a[y] & a[z];
        }
        else{
            int x, v;scanf("%d %d", &x, &v);
            printf("%d", (a[x] & pos[v]).count() % 2);
        }
    }
    printf("\n");
}