#include <bits/stdc++.h>
#define MAXN 1000

int a[MAXN + 1];
int b[MAXN + 1];

int main() {
    FILE * fi, * fout;
    int i, n, k;
    //fi = fopen("A.in" ,"r");
    //fout = fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&k);
    for(i = 1; i <= n; i++)
       fscanf(fi,"%d" ,&a[i]);
    for(i = 1; i <= k; i++)
       fscanf(fi,"%d" ,&b[i]);
    if(k > 1)
       fprintf(fout,"Yes");
    else {
       for(i = 1; i <= n; i++)
         if(a[i] == 0)
           a[i] = b[1];
       i = 2;
       while(i <= n && a[i] > a[i - 1])
          i++;
       if(i == n + 1)
          fprintf(fout,"No");
       else
          fprintf(fout,"Yes");
    }
    //fclose(fi);
   // fclose(fout);
    return 0;
}