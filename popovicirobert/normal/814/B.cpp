#include <bits/stdc++.h>
#define MAXN 1000

int a[MAXN + 1];
int b[MAXN + 1];
int v1[MAXN + 1];
int v2[MAXN + 1];

bool f1[MAXN + 1], f2[MAXN + 1];

int main() {
    FILE * fi, * fout;
    int i, n, j;
    //fi = fopen("A.in" ,"r");
    //fout = fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i = 1; i <= n; i++)
      fscanf(fi,"%d" ,&a[i]);
    for(i = 1; i <= n; i++)
      fscanf(fi,"%d" ,&b[i]);
    for(i = 1; i <= n; i++)
      if(a[i] == b[i]) {
         v1[i] = v2[i] = a[i];
         f1[a[i]] = f2[a[i]] = 1;
      }
    for(i = 1; i <= n; i++)
      if(a[i] != b[i]) {
         j = 1;
         while(f1[j] == 1)
            j++;
         v1[i] = j;
         f1[j] = 1;
      }
    for(i = 1; i <= n; i++)
      if(a[i] != b[i]) {
         j = n;
         while(f2[j] == 1)
            j--;
         v2[i] = j;
         f2[j] = 1;
      }
    int cnt1 = 0, cnt2 = 0;
    for(i = 1; i <= n; i++) {
      if(a[i] != v1[i])
        cnt1++;
      if(b[i] != v1[i])
        cnt2++;
    }
    if(cnt1 == 1 && cnt2 == 1) {
       for(i = 1; i <= n; i++)
         fprintf(fout,"%d " ,v1[i]);
    }
    else
       for(i = 1; i <= n; i++)
         fprintf(fout,"%d " ,v2[i]);
    //fclose(fi);
   // fclose(fout);
    return 0;
}