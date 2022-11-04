#include <bits/stdc++.h>
#define MOD 1000000007
struct Data{
   int con;
   int poz;
};
std::vector <Data> v[1000001];
int pos[1000002];
int vf[1000001];
int x[600000];
int fact[1000001];
bool cmp(int a,int b){
    int i=0;
    while(i<v[a].size()&&i<v[b].size()&&v[a][i].poz==v[b][i].poz&&v[a][i].con==v[b][i].con)
      i++;
  //  printf("%d %d %d\n" ,a,b,i);
    if(i==v[a].size()&&i==v[b].size())
         return a<b;
    if(i==v[a].size())
       return 1;
    if(i==v[b].size())
       return 0;
    return (v[a][i].poz<v[b][i].poz||(v[a][i].poz==v[b][i].poz&&v[a][i].con<v[b][i].con));
}
int main(){
    FILE*fi,*fout;
    int i,n,m,ans,cnt,g,j,p;
   // fi=fopen("C.in" ,"r");
  //  fout=fopen("C.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&m);
    fact[0]=1;
    for(i=1;i<=m;i++)
       fact[i]=(1LL*fact[i-1]*i)%MOD;
    for(i=1;i<=n;i++){
        fscanf(fi,"%d" ,&g);
       // memset(vf,0,sizeof(vf));
        for(j=1;j<=g;j++){
          fscanf(fi,"%d" ,&x[j]);
          vf[x[j]]++;
        }
        for(j=1;j<=g;j++)
        if(vf[x[j]]>0){
           Data aux;
           aux.con=vf[x[j]];
           aux.poz=i;
           v[x[j]].push_back(aux);
           vf[x[j]]=0;
        }
    }
    for(i=1;i<=m;i++)
       pos[i]=i;
    std::sort(pos+1,pos+m+1,cmp);
   // for(i=1;i<=m;i++)
     //   printf("%d " ,pos[i]);
    ans=1;
    cnt=0;
    for(i=1;i<=m;i++){
        if(v[pos[i]].size()==v[pos[i-1]].size()){
             j=0;
             while(j<v[pos[i]].size()&&v[pos[i]][j].con==v[pos[i-1]][j].con&&v[pos[i]][j].poz==v[pos[i-1]][j].poz)
                j++;
             if(j==v[pos[i]].size())
               cnt++;
             else{
                ans=(1LL*ans*fact[cnt])%MOD;
                cnt=1;
             }
        }
        else{
             ans=(1LL*ans*fact[cnt])%MOD;
             cnt=1;
        }
     }
    ans=(1LL*ans*fact[cnt])%MOD;
    fprintf(fout,"%d" ,ans);
  //  fclose(fi);
  //  fclose(fout);
    return 0;
}