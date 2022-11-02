#include<stdio.h>
#include<string.h>
char in[101000];
int ot[300];
char tmp[10];
int main(){
    scanf("%s",in);
    int k;
    scanf("%d",&k);
    while(k--){
        scanf("%s",tmp);
        ot[tmp[0]]=tmp[1];
        ot[tmp[1]]=tmp[0];
    }
    int i,j=0;
    int ans=0;
    for(i=0;in[i];i=j){
        if(ot[in[i]]==0){
            j=i+1;
            continue;
        }
        int c1=0,c2=0;
        while(in[j]&&(in[j]==in[i]||in[j]==ot[in[i]])){
            if(in[j]==in[i])c1++;
            else c2++;
            j++;
        }
        if(c1>c2)c1=c2;
        ans+=c1;
    }
    printf("%d\n",ans);
}