#include <cstdio>
#include <cstdlib>

using namespace std;

int f,a,b,k,c,st,en,sol;

int dis(int x,int y){
    return abs(x - y);
}

int main(){
    scanf("%d %d %d %d",&a,&b,&f,&k);
    c = b;st = 0,en = a;sol = 0;
    for(int i = 0;i<k;i++){
        if(c < dis(st, f)) {printf("-1\n");return 0;}
        if(b + dis(st,f) < a) {printf("-1\n");return 0;}
        if(i == k - 1){
            if(c < a) sol++;
            break;
        }
        if(c < a + dis(en,f)) c = b - dis(f,en),sol++;
        else c -= a;
        if(c < 0) {printf("-1\n");return 0;}
        st ^= en;en ^= st;st ^= en;
    }
    printf("%d\n",sol);
}