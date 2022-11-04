#include <bits/stdc++.h>
#define MAXN 200000
int p[MAXN+1];
bool f[MAXN+1];
std::vector <int> v[4];
bool cmp(const int &a,const int &b){
    return p[a]<p[b];
}
int ind[4];
int main(){
    FILE*fi,*fout;
    int i,n,x,m;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d" ,&n);
    for(i=1;i<=n;i++)
      fscanf(fi,"%d" ,&p[i]);
    for(i=1;i<=n;i++){
      fscanf(fi,"%d" ,&x);
      v[x].push_back(i);
    }
    for(i=1;i<=n;i++){
      fscanf(fi,"%d" ,&x);
      v[x].push_back(i);
    }
    for(i=1;i<=3;i++)
       std::sort(v[i].begin(),v[i].end(),cmp);
    fscanf(fi,"%d" ,&m);
    for(i=1;i<=m;i++){
       fscanf(fi,"%d" ,&x);
       while(ind[x]<v[x].size()&&f[v[x][ind[x]]]==1)
          ind[x]++;
       if(ind[x]<v[x].size()){
          f[v[x][ind[x]]]=1;
          fprintf(fout,"%d " ,p[v[x][ind[x]]]);
       }
       else
          fprintf(fout,"-1 ");
    }
    //fclose(fi);
    //fclose(fout);
    return 0;
}