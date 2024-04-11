#include <cstdio>
int vf[26];
int main(){
   // FILE*fi,*fout;
    int i,n,sum;
    char a;
  //  fi=fopen("B.in" ,"r");
   // fout=fopen("B.out" ,"w");
    scanf("%d " ,&n);
    if(n>26)
       printf("-1");
    else{
        for(i=0;i<n;i++){
           a=fgetc(stdin);
           vf[a-'a']++;
        }
        sum=0;
        for(i=0;i<26;i++)
          if(vf[i]>0)
           sum=sum+vf[i]-1;
        printf("%d" ,sum);
    }
  //  fclose(fi);
   // fclose(fout);
    return 0;
}