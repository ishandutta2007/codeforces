#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1000000
#define c first
#define b second
std::vector < std::pair <int,int> > diamond;
int maxd[MAXN+1];
std::vector < std::pair <int,int> > coin;
int maxc[MAXN+1];
int i;
inline int cb(std::vector < std::pair <int,int> > &v,int x,int *max,bool f){
    int rez=-1;
    for(int pas=1<<18;pas;pas>>=1)
      if(rez+pas<v.size()&&(v[rez+pas].c<=x&&(f==0||(f==1&&v[rez+pas].c<=v[i].c))))
        rez+=pas;
    if(f==1&&rez==i)
      rez--;
      if(rez>-1)
       return max[rez];
      return -INF;
}
int main(){
    FILE*fi,*fout;
    int n,c,d,b,cost,ans;
    char ch;
    //fi=fopen("A.in" ,"r");
    //fout=fopen("A.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d %d %d " ,&n,&c,&d);
    for(i=1;i<=n;i++){
       fscanf(fi,"%d %d %c " ,&b,&cost,&ch);
       if(ch=='C')
          coin.push_back(std::make_pair(cost,b));
       else
          diamond.push_back(std::make_pair(cost,b));
    }
    std::sort(coin.begin(),coin.end());
    std::sort(diamond.begin(),diamond.end());
    if(!coin.empty())
      maxc[0]=coin[0].b;
    for(i=1;i<coin.size();i++)
       maxc[i]=std::max(maxc[i-1],coin[i].b);
    if(!diamond.empty())
      maxd[0]=diamond[0].b;
    for(i=1;i<diamond.size();i++)
       maxd[i]=std::max(maxd[i-1],diamond[i].b);
    ans=-INF;
    for(i=0;i<coin.size();i++)
       if(coin[i].c<=c)
          ans=std::max(ans,coin[i].b+std::max(cb(coin,c-coin[i].c,maxc,1),cb(diamond,d,maxd,0)));
    for(i=0;i<diamond.size();i++)
       if(diamond[i].c<=d){
          ans=std::max(ans,diamond[i].b+std::max(cb(diamond,d-diamond[i].c,maxd,1),cb(coin,c,maxc,0)));
          //printf("%d %d %d\n" ,diamond[i].b,cb(diamond,d-diamond[i].c,maxd,1),i);
          //printf("%d %d %d %d\n" ,ans,d-diamond[i].c,diamond[i].c,diamond[i].b);
        }
    if(ans<0)
      ans=0;
    fprintf(fout,"%d" ,ans);
    //fclose(fi);
    //fclose(fout);
    return 0;
}