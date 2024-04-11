#include <bits/stdc++.h>
#define MAXN 100010
std::vector <int> mat[MAXN+1];
std::vector <int> len[MAXN+1];
int v[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,j,n,m,l,r,max,x,k;
  //  fi=fopen("C.in" ,"r");
  //  fout=fopen("C.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&m);
    for(i=1;i<=m+1;i++){
        mat[0].push_back(0);
        len[0].push_back(0);
    }
    for(i=1;i<=n;i++){
      mat[i].push_back(0);
      len[i].push_back(0);
      for(j=1;j<=m;j++){
       fscanf(fi,"%d" ,&x);
       mat[i].push_back(x);
       len[i].push_back(0);
      }
    }
    for(i=1;i<=m;i++){
      for(j=1;j<=n;j++){
         if(len[j-1][i]>=j)
           len[j][i]=len[j-1][i];
         else{
            l=j;
            while(l<n&&mat[l+1][i]>=mat[l][i])
              l++;
            len[j][i]=l;
         }
      }
    }
    for(i=1;i<=n;i++){
        max=0;
        for(j=1;j<=m;j++)
          max=std::max(max,len[i][j]);
        v[i]=max;
    }
    fscanf(fi,"%d" ,&k);
    while(k>0){
        k--;
        fscanf(fi,"%d%d" ,&l,&r);
        if(v[l]>=r)
          fprintf(fout,"Yes\n");
        else
          fprintf(fout,"No\n");
    }
   // fclose(fi);
   // fclose(fout);
    return 0;
}