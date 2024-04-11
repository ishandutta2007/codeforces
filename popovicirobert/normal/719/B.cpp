#include <cstdio>
char v[100001];
int vf[2][2];
int main(){
    int i,n,con1,con2;
    char a;
    scanf("%d" ,&n);
    a=fgetc(stdin);
    for(i=1;i<=n;i++)
        scanf("%c" ,&v[i]);
    con1=0;
    for(i=1;i<=n;i++){
        if(v[i]=='r')
            vf[0][i%2]++;
        else
            vf[1][i%2]++;
    }
    if(vf[1][1]>vf[0][0])
        con1=vf[1][1];
    else
        con1=vf[0][0];
    if(vf[1][0]>vf[0][1])
         con2=vf[1][0];
    else
         con2=vf[0][1];
    if(con1<con2)
        printf("%d" ,con1);
    else
        printf("%d" ,con2);
    return 0;
}