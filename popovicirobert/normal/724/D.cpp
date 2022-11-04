#include <cstdio>
char v[100001];
int dq[100001];
int vf[27],vf1[27];
int main(){
  // stdinLE*stdin,*fout;
   int i,m,n,b,e,last,min,max;
   char a;
  // stdin=fopen("D.in" ,"r");
  // fout=fopen("D.out" ,"w");
   scanf("%d" ,&m);
   a=fgetc(stdin);
   a=fgetc(stdin);
   n=0;
   while(a>='a'&&a<='z'){
      v[++n]=a-'a';
      vf1[a-'a']++;
      a=fgetc(stdin);
   }
   b=0;
   e=-1;
   for(i=1;i<=m;i++){
       while(e>=b&&v[dq[e]]>=v[i])
          e--;
       dq[++e]=i;
   }
   vf[v[dq[b]]]++;
   last=dq[b];
   for(i=m+1;i<=n;i++){
      if(dq[b]<=i-m)
        b++;
      while(e>=b&&v[dq[e]]>=v[i])
         e--;
      dq[++e]=i;
      if(last<=i-m){
          vf[v[dq[b]]]++;
          last=dq[b];
      }
   }
   min=29;
   max=0;
   for(i=0;i<26;i++){
       if(vf[i]>0&&min>i)
          min=i;
       if(vf[i]>0&&max<i)
          max=i;
   }
   for(i=0;i<max;i++)
     while(vf1[i]>0){
       vf1[i]--;
       printf("%c" ,i+'a');
     }
   while(vf[max]>0){
      printf("%c" ,max+'a');
      vf[max]--;
   }
  // fclose(stdin);
  // fclose(fout);
   return 0;
}