#include <cstdio>
#define MAXN 200000
#define LOG 19
int v[MAXN+1],rmq[2][MAXN+1][LOG],pow[MAXN+1];
int main(){
   // FILE*fi,*fout;
    int p2,i,n,pozmax,max,min,pozmin,m,con,j,l,r,x;
  //  fi=fopen("C.in" ,"r");
   // fout=fopen("C.out" ,"w");
    scanf("%d%d" ,&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d" ,&v[i]);
    p2=1;
    con=0;
    for(i=1;i<=n;i++){
          if(p2*2<=i){
             p2*=2;
             con++;
          }
          pow[i]=con;
          rmq[0][i][0]=rmq[1][i][0]=i;
    }
    for(i=1;(1<<i)<=n;i++)
        for(j=1;j+(1<<i)<=n+1;j++){
            if(v[rmq[0][j][i-1]]>v[rmq[0][j+(1<<(i-1))][i-1]])
               rmq[0][j][i]=rmq[0][j][i-1];
            else
               rmq[0][j][i]=rmq[0][j+(1<<(i-1))][i-1];
            if(v[rmq[1][j][i-1]]<v[rmq[1][j+(1<<(i-1))][i-1]])
               rmq[1][j][i]=rmq[1][j][i-1];
            else
               rmq[1][j][i]=rmq[1][j+(1<<(i-1))][i-1];
        }
    for(i=1;i<=m;i++){
        scanf("%d%d%d" ,&l,&r,&x);
        if(v[rmq[0][l][pow[r-l+1]]]>v[rmq[0][r-(1<<(pow[r-l+1]))+1][pow[r-l+1]]]){
            max=v[rmq[0][l][pow[r-l+1]]];
            pozmax=rmq[0][l][pow[r-l+1]];
        }
        else{
            max=v[rmq[0][r-(1<<(pow[r-l+1]))+1][pow[r-l+1]]];
            pozmax=rmq[0][r-(1<<(pow[r-l+1]))+1][pow[r-l+1]];
        }
        if(v[rmq[1][l][pow[r-l+1]]]<v[rmq[1][r-(1<<(pow[r-l+1]))+1][pow[r-l+1]]]){
            min=v[rmq[1][l][pow[r-l+1]]];
            pozmin=rmq[1][l][pow[r-l+1]];
        }
        else{
            min=v[rmq[1][r-(1<<(pow[r-l+1]))+1][pow[r-l+1]]];
            pozmin=rmq[1][r-(1<<(pow[r-l+1]))+1][pow[r-l+1]];
        }
        if(max==x){
            if(min==x)
               printf("-1\n");
            else
               printf("%d\n" ,pozmin);
        }
        else
            printf("%d\n" ,pozmax);
    }
 //   fclose(fi);
 //   fclose(fout);
    return 0;
}