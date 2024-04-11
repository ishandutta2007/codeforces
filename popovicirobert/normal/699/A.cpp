#include <cstdio>
char v[200001];
int x[200001];
int main(){
    int i,n,min;
    scanf("%d " ,&n);
    for(i=1;i<=n;i++)
      scanf("%c" ,&v[i]);
    for(i=1;i<=n;i++)
      scanf("%d" ,&x[i]);
    min=1000000000;
    for(i=2;i<=n;i++){
       if(v[i-1]=='R'&&v[i]=='L'&&min>(x[i]-x[i-1])/2)
         min=(x[i]-x[i-1])/2;
    }
    if(min==1000000000)
      min=-1;
    printf("%d" ,min);
    return 0;
}