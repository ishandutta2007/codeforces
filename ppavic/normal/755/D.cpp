#include <cstdio>

using namespace std;

typedef long long int llint;

const int N = 2e6 + 500;

int fen[N];
int cur = 1;
int n,k;
llint rez = 1;

void add(int i){
    for(;i < N;i += i &-i)
        fen[i]++;
}

int sol(int i){
    if(!i) return 0;
    int ret = 0;
    for(;i>0;i-=i&-i)
        ret += fen[i];
    return ret;
}

int main(){
    scanf("%d%d",&n,&k);
    if(n -k < k){
        k = n - k;
    }
    for(int i = 0;i<n;i++){
        int nw = cur + k;
        int pov = sol(nw - 1) - sol(cur);
        if(nw > n){
            add(nw);add(nw-n);
            nw -= n;
        }
        else{
            add(nw);add(nw+n);
        }
        add(cur);add(cur+n);
        cur = nw;
        rez += (llint)pov + 1;
        printf("%I64d\n",rez);
    }
}