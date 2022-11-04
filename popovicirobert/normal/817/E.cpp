#include <bits/stdc++.h>

struct Trie{
    Trie *son[2];
    int sz;
    Trie() {
       memset(son, 0, sizeof(son));
       sz = 0;
    }
};
Trie *T = new Trie;

void insert(Trie *nod, int p, int sz, int lg) {
    if(lg == -1)
        nod -> sz += sz;
    else {
        int r = (((1 << lg) & p) > 0);
        if(nod -> son[r] == 0)
          nod -> son[r] = new Trie;
        insert(nod -> son[r], p, sz, lg - 1);
        nod -> sz += sz;
    }
}

int ans;

void solve(Trie *nod, int p, int l, int lg) {
    if(nod == 0)
      return ;
    if(lg == -1)
         ans += nod -> sz;
    else {
       int r = (((1 << lg) & l) > 0);
       if((p & (1 << lg)) == 0) {
          if(r == 0)
              solve(nod -> son[0], p, l, lg - 1);
          else {
              if(nod -> son[0] != NULL)
                ans += nod -> son[0] -> sz;
              solve(nod -> son[1], p, l, lg - 1);
          }
       }
       else {
          if(r == 0)
             solve(nod -> son[1], p, l, lg - 1);
          else {
             if(nod -> son[1] != NULL)
                ans += nod -> son[1] -> sz;
             solve(nod -> son[0], p, l, lg - 1);
          }
       }
    }
}

int main() {
    FILE * fi, * fout;
    int i,q,tip,p,l;
    //fi = fopen("A.in" ,"r");
    //fout = fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&q);
    while(q > 0) {
       q--;
       fscanf(fi,"%d" ,&tip);
       if(tip==1) {
           fscanf(fi,"%d" ,&p);
           insert(T, p, 1, 27);
       }
       else if(tip==2){
           fscanf(fi,"%d" ,&p);
           insert(T, p, -1, 27);
       }
       else {
           fscanf(fi,"%d%d" ,&p, &l);
           ans=0;
           solve(T, p, l - 1, 27);
           fprintf(fout,"%d\n" ,ans);
       }
    }
    //fclose(fi);
    //fclose(fout);
    return 0;
}