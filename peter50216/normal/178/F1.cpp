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
map<int,int> trie[1000100];
int cnt[1000100];
char tmp[1000];
int tc;
struct XD{
    int y,l;
    XD(int yy=-1,int ll=-1):y(yy),l(ll){}
};
vector<XD> ed[5000];
int nn;
inline void run(int np,int p){
    int i;
    map<int,int>::iterator it;
    for(it=trie[np].begin();it!=trie[np].end();it++){
        int cnt=0;
        int k=it->second,f=0;
        while(1){
            if(k<0){
                //cnt+=k;
                break;
            }
            if(trie[k].size()==0){
                cnt++;
                break;
            }
            if(trie[k].size()==1){
                cnt++;
                k=(trie[k].begin()->second);
            }else{
                cnt++;
                f=1;
                break;
            }
        }
        int pp=nn;
        nn++;
        ed[p].push_back(XD(pp,cnt));
        if(f){
            run(k,pp);
        }
    }
}
int dp[5010][5010];
inline int dpf(int np,int lp,int li){
    if(ed[np].size()==0){
        if(lp==1)return 0;
        else return -2;
    }
    int y=ed[np][li].y;
    int &d=dp[y][lp];
    if(d!=-1)return d;
    d=-2;
    // last one
    if(li+1==ed[np].size()){
        int r=dpf(y,lp,0);
        if(r==-2)d=-2;
        else d=r+ed[np][li].l*(lp*(lp-1)/2);
    }else{
        int k;
        int r;
        //select 0.
        r=dpf(np,lp,li+1);
        if(r!=-2)d=max(d,r);
        //select all
        r=dpf(y,lp,0);
        if(r!=-2)d=max(d,r+ed[np][li].l*(lp*(lp-1)/2));
        //select some
        for(k=1;k<lp;k++){
            int r1=dpf(y,k,0);
            if(r1==-2)continue;
            int r2=dpf(np,lp-k,li+1);
            if(r2==-2)continue;
            d=max(d,r1+r2+ed[np][li].l*(k*(k-1)/2));
        }
    }
    //printf("np=%d lp=%d li=%d d=%d\n",np,lp,li,d);
    return d;
}
int main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    tc=1;
    for(i=0;i<n;i++){
        scanf("%s",tmp);
        int np=0;
        map<int,int>::iterator it;
        for(j=0;tmp[j];j++){
            it=trie[np].find(tmp[j]-'a');
            int to;
            if(it==trie[np].end()){
                trie[np][tmp[j]-'a']=tc;
                to=tc;
                tc++;
            }else{
                to=it->second;
            }
            np=to;
        }
        trie[np][26+cnt[np]]=-1;
        cnt[np]++;
    }
    nn=1;
    run(0,0);
    //printf("nn=%d\n",nn);
    //for(i=0;i<nn;i++)for(j=0;j<ed[i].size();j++)printf("%d -> %d (%d)\n",i,ed[i][j].y,ed[i][j].l);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dpf(0,k,0));
}