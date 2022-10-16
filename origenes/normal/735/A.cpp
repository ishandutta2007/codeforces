#include <cstdio>
#include <cstring>
inline int abs(int a){
    return a>0?a:(-1)*a;
}
bool str[105];
int main(){
    int n, k, g, t, diff;
    scanf("%d%d", &n, &k);
    getchar();
    memset(str, false, sizeof(str));
    for(int i=0; i<n; i++){
        char c=getchar();
        if(c=='#') continue;
        str[i]=true;
        if(c=='G') g=i;
        else if(c=='T') t=i;
    }
    diff=abs(g-t);
    if(diff%k){
        printf("NO\n");
        return 0;
    }
    if(g<t){
        for(int i=g; i<=t; i+=k){
            if(!str[i]){
                printf("NO\n");
                return 0;
            }
        }
    }else{
        for(int i=t; i<=g; i+=k){
            if(!str[i]){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}