#include <cstdio>
#define MAXN 500000
int per[MAXN+1],stiv[MAXN+1],next[MAXN+1],prev[MAXN+1];
char sir[MAXN+1];
int main(){
  //  FILE*fi,*fout;
    int n,m,p,poz,ist,i;
    char a;
    //fi=fopen("E.in" ,"r");
   // fout=fopen("E.out" ,"w");
    scanf("%d %d %d " ,&n,&m,&p);
    ist=-1;
    for(i=1;i<=n;i++){
       a=fgetc(stdin);
       sir[i]=a;
       next[i]=(i+1)%(n+1);
       prev[i]=i-1;
       if(a=='(')
          stiv[++ist]=i;
       else{
          per[i]=stiv[ist];
          per[stiv[ist]]=i;
          ist--;
       }
    }
    a=fgetc(stdin);
    ist=-1;
    for(i=1;i<=p;i++)
       stiv[++ist]=i;
    poz=p;
    for(i=1;i<=m;i++){
        a=fgetc(stdin);
        if(a=='L'){
            ist--;
            poz=stiv[ist];
        }
        if(a=='R'){
            poz=next[poz];
            stiv[++ist]=poz;
        }
        if(a=='D'){
            if(per[poz]<poz){
                while(stiv[ist]!=per[poz])
                   ist--;
                ist--;
             //   printf("%d " ,stiv[ist]);
                next[stiv[ist]]=next[poz];
                prev[next[poz]]=stiv[ist];
                poz=stiv[ist];
                if(next[poz]>0){
                   poz=next[poz];
                   stiv[++ist]=poz;
                }
            }
            else{
                ist--;
                prev[next[per[poz]]]=prev[poz];
                next[prev[poz]]=next[per[poz]];
                poz=prev[poz];
                if(next[poz]>0){
                   poz=next[poz];
                   stiv[++ist]=poz;
                }
            }
        }
    }
    poz=stiv[0];
    while(poz>0){
        printf("%c" ,sir[poz]);
        poz=next[poz];
    }
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}