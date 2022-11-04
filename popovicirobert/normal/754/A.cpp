#include <bits/stdc++.h>
int v[110];
int dp[110];
int poz[110];
int l[110],r[110];
int main(){
   FILE*fi,*fout;
   int n,i,p,s,ans,j;
 //  fi=fopen("A.in" ,"r");
 //  fout=fopen("A.out" ,"w");
   fi=stdin;
   fout=stdout;
   fscanf(fi,"%d" ,&n);
   for(i=1;i<=n;i++)
     fscanf(fi,"%d" ,&v[i]);
   dp[0]=1;
   for(i=1;i<=n;i++){
     s=v[i];
     for(j=i-1;j>=0;j--){
        if(s!=0&&dp[j]==1){
           dp[i]=1;
           poz[i]=j+1;
        }
        s+=v[j];
     }
   }
   p=n;
   ans=0;
   while(p>0){
      ans++;
      l[ans]=poz[p];
      r[ans]=p;
      p=poz[p]-1;
   }
   if(dp[n]==1){
     fprintf(fout,"YES\n%d\n" ,ans);
     for(i=ans;i>0;i--)
       fprintf(fout,"%d %d\n" ,l[i],r[i]);
   }
   else
     fprintf(fout,"NO");
  // fclose(fi);
 //  fclose(fout);
   return 0;
}