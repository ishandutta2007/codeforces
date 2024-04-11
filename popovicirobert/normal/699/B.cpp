#include <cstdio>
int sl[1001],sc[1001];
char mat[1001][1001];
int main(){
  // FILE*fi,*fout;
   int i,j,n,m,l,c,con,flag;
   char a;
  // fi=fopen("B.in" ,"r");
  // fout=fopen("B.out" ,"w");
   scanf("%d %d " ,&n,&m);
   con=0;
   for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        a=fgetc(stdin);
        if(a=='*'){
           con++;
           sl[i]++;
           sc[j]++;
        }
        mat[i][j]=a;
      }
      a=fgetc(stdin);
   }
   flag=1;
   for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
       if(sl[i]+sc[j]-(mat[i][j]=='*')==con){
          flag=0;
          l=i;
          c=j;
       }
   if(flag==0)
      printf("YES\n%d %d" ,l,c);
   else
      printf("NO");
  // fclose(fi);
  // fclose(fout);
   return 0;
}