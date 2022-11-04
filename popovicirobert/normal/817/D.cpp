#include <bits/stdc++.h>
#define MAXN 1000000
struct Data{
  int left;
  int right;
}min[MAXN + 1],max[MAXN + 1];
int stiv[MAXN + 1];
int v[MAXN + 1];

int main() {
    FILE * fi, * fout;
    int i,n,ist;
   // fi = fopen("A.in" ,"r");
   // fout = fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++)
      fscanf(fi,"%d" ,&v[i]);
    ist=-1;
    for(i=1;i<=n;i++) {
       while(ist>=0&&v[i]>v[stiv[ist]]) {
          max[stiv[ist]].right=i-1;
          ist--;
       }
       stiv[++ist]=i;
    }
    while(ist>=0){
       max[stiv[ist]].right=n;
       ist--;
    }
    ist=-1;
    for(i=n;i>=1;i--) {
       while(ist>=0&&v[i]>=v[stiv[ist]]) {
          max[stiv[ist]].left=i+1;
          ist--;
       }
       stiv[++ist]=i;
    }
    while(ist>=0){
       max[stiv[ist]].left=1;
       ist--;
    }

    ist=-1;
    for(i=1;i<=n;i++) {
       while(ist>=0&&v[i]<v[stiv[ist]]) {
          min[stiv[ist]].right=i-1;
          ist--;
       }
       stiv[++ist]=i;
    }
    while(ist>=0){
       min[stiv[ist]].right=n;
       ist--;
    }
    ist=-1;
    for(i=n;i>=1;i--) {
       while(ist>=0&&v[i]<=v[stiv[ist]]) {
          min[stiv[ist]].left=i+1;
          ist--;
       }
       stiv[++ist]=i;
    }
    while(ist>=0){
       min[stiv[ist]].left=1;
       ist--;
    }
    long long ans = 0;
    for(i=1;i<=n;i++)
       ans += 1LL * v[i] * (1LL * (i-max[i].left+1)*(max[i].right-i+1) - 1LL * (i-min[i].left+1)*(min[i].right-i+1));
    fprintf(fout,"%I64d" ,ans);
   // fclose(fi);
   // fclose(fout);
    return 0;
}