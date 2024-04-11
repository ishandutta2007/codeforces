#include <cstdio>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int k,n;
int sol[N];

void mergesrt(int l,int r,int lo){
    if(l + 1 == r){
        sol[l] = lo;
        return;
    }
    if(!k){
        for(int i = l;i<r;i++){
            sol[i] = lo++;
        }
        return;
    }
    int mid = (l + r) / 2;
    k-=2;
    mergesrt(l, mid, lo + r - mid);
    mergesrt(mid , r     , lo);
}

int main(){
    scanf("%d %d",&n,&k);k--;
    mergesrt(0,n,1);
    if(k != 0){
        printf("-1\n");
        return 0;
    }
    for(int i = 0;i<n;i++)
        printf("%d\n",sol[i]);
    return 0;
}