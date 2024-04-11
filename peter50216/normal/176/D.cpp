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
string ba[2010];
char tmp[1010000];
int id[2010];
char s[2010];
pair<int,int> dp[2010][2010];
int cnt[2010][30];
int c2[2010][30];
vector<int> pid[2010][30];
inline void relax(pair<int,int>& x,const pair<int,int>& y){
    if(x<y)x=y;
}
int n,m;
inline pair<int,int> find_pre(const pair<int,int>& np,int c){
    int q=np.first,w=np.second;
    if(w==0){
        if(q==0)return make_pair(-1,-1);
        q--;
        w=ba[id[q]].size()-1;
    }else w--;
   // printf("q=%d w=%d %d\n",q,w,id[q]);
    int qq=id[q];
    if(!pid[qq][c].empty()){
        vector<int>::iterator it=upper_bound(pid[qq][c].begin(),pid[qq][c].end(),w);
        if(it!=pid[qq][c].begin()){
            //puts("Not begin");
            it--;
            return make_pair(q,*it);
        }
    }
    if(q==0)return make_pair(-1,-1);
    int l=0,r=q-1;
    while(l<r){
        //printf("l=%d r=%d\n",l,r);
        int m=(l+r+1)/2;
        if(c2[m][c]==c2[q][c])r=m-1;
        else l=m;
    }
    //for(int i=0;i<q;i++)printf("c2[%d][%d]=%d\n",i,c,c2[i][c]);
   // printf("l=%d\n",l);
    if(c2[l][c]==c2[q][c])return make_pair(-1,-1);
    return make_pair(l,*pid[id[l]][c].rbegin());
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",tmp);
        ba[i]=tmp;
        for(j=0;tmp[j];j++){
            cnt[i][tmp[j]-'a']++;
            pid[i][tmp[j]-'a'].push_back(j);
        }
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&id[i]);
        for(j=0;j<26;j++)c2[i+1][j]=c2[i][j]+cnt[id[i]][j];
    }
    scanf("%s",s);
    int l=strlen(s);
    for(i=0;i<=l;i++)for(j=0;j<=l;j++)dp[i][j]=make_pair(-1,-1);
    dp[l][0]=make_pair(m,0);
    for(i=l-1;i>=0;i--){
        for(j=0;j<=l-i;j++){
           // printf("i=%d j=%d\n",i,j);
            if(j<l-i){
                relax(dp[i][j],dp[i+1][j]);
            }
            if(j){
                relax(dp[i][j],find_pre(dp[i+1][j-1],s[i]-'a'));
            }
          //  printf("           %d %d = %d %d\n",i,j,dp[i][j].first,dp[i][j].second);
        }
    }
    for(j=l;j>=0;j--)if(dp[0][j].first!=-1)break;
    printf("%d\n",j);
}