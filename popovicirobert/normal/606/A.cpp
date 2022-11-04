#include <cstdio>
int mat[2][3];
int main(){
   // FILE*fi,*fout;
    int i,j,nr,con;
   // fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    for(i=0;i<2;i++)
       for(j=0;j<3;j++)
           scanf("%d" ,&mat[i][j]);
    con=nr=0;
    for(i=0;i<3;i++)
       if(mat[0][i]<mat[1][i])
           con+=(mat[1][i]-mat[0][i]);
       else{
           if((mat[0][i]-mat[1][i])%2==1)
              nr--;
           nr+=(mat[0][i]-mat[1][i]);
       }
    if(2*con<=nr)
       printf("Yes");
    else
       printf("No");
  //  fclose(fi);
   // fclose(fout);
    return 0;
}