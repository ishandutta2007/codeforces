#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> di[101000];
bool ison[101000];
int cnt[101000];
vector<int> as[101000];
inline void seton(int x){
    ison[x]=1;
    for(int i=1;i<di[x].size();i++){
        cnt[di[x][i]]++;
        as[di[x][i]].push_back(x);
    }
}
inline void setoff(int x){
    ison[x]=0;
    for(int i=1;i<di[x].size();i++)cnt[di[x][i]]--;
}
inline int conf(int x){
    int i;
    for(i=1;i<di[x].size();i++){
        if(cnt[di[x][i]]){
            while(1){
                int r=as[di[x][i]][as[di[x][i]].size()-1];
                if(ison[r])return r;
                as[di[x][i]].pop_back();
            }
        }
    }
    return -1;
}
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    vector<int> d2;
    for(i=1;i<=n;i++){
        d2.clear();
        for(j=1;j*j<=i;j++){
            if(i%j==0){
                di[i].push_back(j);
                if(j*j!=i)d2.push_back(i/j);
            }
        }
        for(j=d2.size()-1;j>=0;j--)di[i].push_back(d2[j]);
    }
    while(m--){
        char tmp[10];
        int x;
        scanf("%s%d",tmp,&x);
        if(tmp[0]=='+'){
            if(ison[x])puts("Already on");
            else{
                int d=conf(x);
                if(d==-1){
                    seton(x);
                    puts("Success");
                }else printf("Conflict with %d\n",d);
            }
        }else{
            if(!ison[x])puts("Already off");
            else{
                setoff(x);
                puts("Success");
            }
        }
    }
}