#include <cstdio>
int vf[1000],vf1[1000];
char v[100009];
int main(){
    int n,b,e,min,x,con,i;
    char a;
    scanf("%d " ,&n);
    con=0;
    for(i=1;i<=n;i++){
        scanf("%c" ,&a);
        v[i]=a;
        if(vf[a]==0)
          con++;
        vf[a]++;
    }
    b=e=1;
    x=0;
    min=n;
    while(b<=n){
       while(e<=n&&x<con){
          if(vf1[v[e]]==0)
            x++;
          vf1[v[e]]++;
          e++;
       }
       if(x==con){
          if(min>e-b)
            min=e-b;
       }
       if(vf1[v[b]]==1)
          x--;
       vf1[v[b]]--;
       b++;
    }
    printf("%d" ,min);
    return 0;
}