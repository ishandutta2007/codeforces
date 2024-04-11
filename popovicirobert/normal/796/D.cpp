#include <bits/stdc++.h>
#define MAXN 300000
#define nod first
#define poz second
std::vector < std::pair <int,int> > g[MAXN+1];
bool f[MAXN+1];
int q[MAXN+1];
int cul[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n,k,d,j,ans,x,b,e,a;
   // fi=fopen("D.in" ,"r");
   // fout=fopen("D.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d%d" ,&n,&k,&d);
    ans=0;
    for(i=1;i<=k;i++){
        fscanf(fi,"%d" ,&x);
        if(f[x]==0)
          ans++;
        f[x]=1;
    }
    for(i=1;i<n;i++){
        fscanf(fi,"%d%d" ,&a,&b);
        g[a].push_back(std::make_pair(b,i));
        g[b].push_back(std::make_pair(a,i));
    }
    fprintf(fout,"%d\n" ,ans-1);
    b=e=0;
    for(i=1;i<=n;i++)
      if(f[i]==1){
        q[e++]=i;
        cul[i]=i;
      }
    do{
        int nod=q[b];
        b++;
        for(i=0;i<g[nod].size();i++)
         if(cul[g[nod][i].nod]==0){
            cul[g[nod][i].nod]=cul[nod];
            q[e++]=g[nod][i].nod;
         }
    }while(b<e);
    for(i=1;i<=n;i++)
     for(j=0;j<g[i].size();j++)
      if(i<g[i][j].nod&&cul[i]!=cul[g[i][j].nod])
        fprintf(fout,"%d " ,g[i][j].poz);
    //fclose(fi);
   // fclose(fout);
    return 0;
}