#include <bits/stdc++.h>
#define MAXN 100
struct Data{
   int t;
   int k;
   std::vector <int> id;
   bool operator <(const Data &x) const{
      return t>x.t;
   }
};
std::priority_queue <Data> pq;
bool f[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,n,q,con,x,t,k,d,j,ans;
   // fi=fopen("C.in" ,"r");
   // fout=fopen("C.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&q);
    con=n;
    for(i=1;i<=q;i++){
        fscanf(fi,"%d%d%d" ,&t,&k,&d);
        x=0;
        while(pq.empty()==0&&pq.top().t<=t){
            x+=pq.top().k;
            for(j=0;j<pq.top().id.size();j++)
                f[pq.top().id[j]]=0;
            pq.pop();
        }
        con+=x;
        if(con>=k){
            int k1=k;
            con-=k;
            Data aux;
            ans=0;
            for(j=1;j<=n&&k>0;j++)
             if(f[j]==0){
               f[j]=1;
               k--;
               ans+=j;
               aux.id.push_back(j);
             }
             aux.t=t+d;
             aux.k=k1;
             pq.push(aux);
             fprintf(fout,"%d\n" ,ans);
        }
        else
            fprintf(fout,"-1\n");
    }

   // fclose(fi);
   // fclose(fout);
    return 0;
}