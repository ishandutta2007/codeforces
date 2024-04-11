#include <cstdio>
int lin[]={4,1,1,1,2,2,2,3,3,3},col[]={2,1,2,3,1,2,3,1,2,3};
int mat[6][6];
int dl[]={-1,0,1,0},dc[]={0,1,0,-1};
inline int cauta(int l,int c){
    int i=0;
    while(i<10&&!(l==lin[i]&&c==col[i]))
       i++;
    return i<10;
}
int main(){
    int i,n,j,con,nr,flag;
    char x;
    scanf("%d " ,&n);
    nr=0;
    for(i=1;i<=n;i++){
      scanf("%c" ,&x);
      x-='0';
      if(mat[lin[x]][col[x]]==0)
        nr++;
      mat[lin[x]][col[x]]=1;
    }
    flag=0;
    for(i=0;i<4;i++){
       con=0;
       for(j=0;j<=9;j++)
        if(mat[lin[j]][col[j]]==1&&cauta(lin[j]+dl[i],col[j]+dc[i])==1)
           con++;
       if(con==nr)
        flag=1;
    }
    if(flag==0)
        printf("YES");
    else
        printf("NO");
    return 0;
}