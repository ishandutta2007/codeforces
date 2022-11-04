#include <cstdio>
#define MAXN 200010
int vf[MAXN+1];
int v[MAXN+1];
int main(){
    FILE*fi,*fout;
    int i,j,n,s,max,poz,ind,ans,x;
   // fi=fopen("E.in" ,"r");
   // fout=fopen("E.out" ,"w");
    fi=stdin;
    fout=stdout;
    fscanf(fi,"%d%d" ,&n,&s);
    ans=0;
    max=0;
    for(i=1;i<=n;i++){
       fscanf(fi,"%d" ,&v[i]);
       vf[v[i]]++;
       if(max<v[i])
          max=v[i];
    }
    max++;
    if(v[s]!=0){
        ans++;
        vf[v[s]]--;
        vf[max]=vf[0];
        vf[0]=1;
    }
    else{
        vf[max]=vf[0]-1;
        vf[0]=1;
    }
    i=0;
    poz=max;
    while(i<max){
        j=i+1;
        while(j<=max&&vf[j]==0)
          j++;
        x=j-i-1;
        ind=i+1;
        while(x>0&&poz>=j){
           while(x>0&&vf[poz]>0){
              vf[poz]--;
              vf[ind]++;
              ans++;
              x--;
              ind++;
           }
           if(vf[poz]==0)
             poz--;
        }
        i=j;
    }
    if(vf[max]>0)
      ans+=vf[max];
    fprintf(fout,"%d" ,ans);
   // fclose(fi);
   // fclose(fout);
    return 0;
}