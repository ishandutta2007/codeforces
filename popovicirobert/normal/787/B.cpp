#include <bits/stdc++.h>
#define MAXN 10000
int vf1[MAXN+1];
int vf2[MAXN+1];
int main(){
    int i,n,m,x;
    scanf("%d%d" ,&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d " ,&n);
        bool flag=0;
        for(int j=1;j<=n;j++){
            scanf("%d" ,&x);
            if(x<0){
                x=-x;
                if(vf2[x]==i)
                   flag=1;
                vf1[x]=i;
            }
            else{
                if(vf1[x]==i) 
                  flag=1;
                vf2[x]=i;
            }
        }
        if(flag==0){
          printf("YES");
          return  0;
        }
    }
    printf("NO");
    return 0;
}