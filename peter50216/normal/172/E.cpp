#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
char in[1010000];
vector<int> ed[300000];
int nid[300000];
int n;
int pre[300000];
map<string,int> XD;
int xc=0;
inline int ton(const string& str){
    map<string,int>::iterator it;
    if((it=XD.find(str))==XD.end()){
        return XD[str]=xc++;
    }
    return it->second;
}
inline void wu(int& np){
    np=pre[np];
}
inline void wd(int& np,int id){
    ed[np].push_back(n);
    nid[n]=id;
    pre[n]=np;
    np=n;
    n++;
}
char tmp[10000];
vector<int> qu;
int dp[301000];
inline void dfs(int np){
    if(np==0){
        dp[0]=0;
    }else{
        int r=dp[pre[np]];
        dp[np]=r;
        if(r!=qu.size()&&nid[np]==qu[r])dp[np]++;
    }
   // printf("np=%d dp=%d\n",np,dp[np]);
    for(int i=0;i<ed[np].size();i++)dfs(ed[np][i]);
}
int main(){
    scanf("%s",in);
    pre[0]=-1;
    nid[0]=-1;
    n=1;
    int i,np=0,j;
    string str="";
    for(i=0;in[i];i++){
        if(in[i]=='<')continue;
        if(in[i]=='>'){
            if(str[0]=='/'){
                str=str.substr(1);
                wu(np);
            }else if(str[str.size()-1]=='/'){
                str=str.substr(0,str.size()-1);
                wd(np,ton(str));
                wu(np);
            }else{
                wd(np,ton(str));
            }
            str="";
        }else str+=in[i];
    }
    /*for(i=0;i<n;i++){
        printf("%d(%d) ->",i,nid[i]);
        for(j=0;j<ed[i].size();j++)printf(" %d",ed[i][j]);
        puts("");
    }*/
    int q;
    scanf("%d",&q);
    gets(tmp);
    while(q--){
        gets(tmp);
        qu.clear();
        char* c=strtok(tmp," ");
        while(c!=NULL){
            qu.push_back(ton(c));
            c=strtok(NULL," ");
        }
        //for(i=0;i<qu.size();i++)printf("    %d",qu[i]);puts("");
        dfs(0);
        int cnt=0;
        for(i=0;i<n;i++)if(nid[i]==qu[qu.size()-1]&&dp[i]==qu.size())cnt++;
        printf("%d\n",cnt);
    }
}