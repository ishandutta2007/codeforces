#include<stdio.h>
#include<string.h>
char a[1000],b[1000];
char t[1000];
int gn(int aa){
    sprintf(t,"%d",aa);
    int c=0;
    for(int i=0;t[i];i++)if(t[i]!='0')a[c++]=t[i];
    if(c==0)a[c++]='0';
    a[c]=0;
    int x;
    sscanf(a,"%d",&x);
    return x;
}
char q[1000],w[1000];
int main(){
    int qq,ww;
    scanf("%s%s",q,w);
    sscanf(q,"%d",&qq);
    sscanf(w,"%d",&ww);
    int ee=qq+ww;
    puts(gn(qq)+gn(ww)==gn(ee)?"YES":"NO");
}