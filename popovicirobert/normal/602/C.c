#include <stdio.h>
#include <stdlib.h>
#define MAXN 400
int drum[MAXN+1][MAXN+1],cod[MAXN],lung[2][MAXN+1];
int BFS(int nod,int tip,int n){
    int i,b,e;
    cod[0]=nod;
    lung[tip][nod]=1;
    b=0;
    e=1;
    do{
        for(i=1;i<=n;i++)
           if(lung[tip][i]==0&&drum[i][cod[b]]==tip){
               cod[e]=i;
               e++;
               lung[tip][i]=lung[tip][cod[b]]+1;
           }
        b++;
    }while(b<e);
    return lung[tip][n];
}
int main(){
   // FILE*fi,*fout;
    int x,y,i,n,m,max;
   // fi=fopen("C.in" ,"r");
  //  fout=fopen("C.out" ,"w");
    scanf("%d%d" ,&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d" ,&x,&y);
        drum[x][y]=drum[y][x]=1;
    }
    if(BFS(1,0,n)==0||BFS(1,1,n)==0)
       printf("-1");
    else{
        int max1,max2;
        max1=BFS(1,0,n);
        max2=BFS(1,1,n);
        if(max1>max2)
           max=max1;
        else
           max=max2;
        printf("%d" ,max-1);
    }
 //   fclose(fi);
  //  fclose(fout);
    return 0;
}