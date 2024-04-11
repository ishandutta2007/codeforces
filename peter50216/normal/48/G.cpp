#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
const int MAXN = 200010;
struct XD{
    int y,l;
    XD(int yy=0,int ll=0):y(yy),l(ll){}
};
vector<XD> ed[MAXN];
int stk[2*MAXN][2],sc;
int vis[MAXN];
int onc[MAXN];
int pre[MAXN];
int prei[MAXN];
vector<pair<int,int> > cyc;
inline void dfs(int st){
    sc=0;
    stk[sc][0]=st;
    stk[sc][1]=0;
    sc++;
    pre[st]=-1;
    vis[st]=1;
    bool ced = 0;
    while(sc){
    int np=stk[sc-1][0],i=stk[sc-1][1];
    sc--;
    if(i==ed[np].size())continue;
    if(ed[np][i].y==pre[np]){
        stk[sc][0]=np;stk[sc][1]=i+1;sc++;continue;
    }
    int y=ed[np][i].y;
    if(vis[y]){
        if(ced)continue;
//      printf("np=%d y=%d\n",np,y);
        // Found the cycle;
        for(int x=np;x!=y;x=pre[x]){
//      printf("# %d %d %d\n",x,pre[x],prei[x]);
        cyc.push_back(make_pair(pre[x],prei[x]));
        onc[pre[x]]=1;
        }
        cyc.push_back(make_pair(np,i));
        onc[np]=1;
        ced=1;
        continue;
    }
    pre[y]=np;
    prei[y]=i;
    vis[y]=1;
    stk[sc][0]=np;stk[sc][1]=i+1;sc++;
    stk[sc][0]=y;stk[sc][1]=0;sc++;
    }
}
long long ans[MAXN];
int cycc;
int dp[MAXN];
long long tor[MAXN];
int root[MAXN];
inline long long dfshei(int np,int p,int& num,long long to,int rr){
    int i;
    long long ret=0;
    tor[np]=to;
    root[np]=rr;
    num=1;
    for(i=0;i<ed[np].size();i++){
    int y=ed[np][i].y;
    if(y==p)continue;
    if(onc[y])continue;
    int s;
    long long w=dfshei(y,np,s,to+ed[np][i].l,rr);
    ret+=s*ed[np][i].l+w;
    num+=s;
    }
    dp[np]=num;
    return ret;
}
inline void dfs2(int np,int p,long long ls,int totp){
    ans[np]+=ls;
    int i;
    for(i=0;i<ed[np].size();i++){
    int y=ed[np][i].y;
    if(y==p)continue;
    if(onc[y])continue;
    dfs2(y,np,ls+(totp-dp[y]-dp[y])*ed[np][i].l,totp);
    }
}
long long totd[MAXN];
int cycl[MAXN];
int tt[MAXN];
//long long tots[MAXN];
int cn[MAXN];
//long long totlw[MAXN];
//long long totl[MAXN];
long long ansc[MAXN];
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    int x,y,l;
    scanf("%d%d%d",&x,&y,&l);
    x--;y--;
    ed[x].push_back(XD(y,l));
    ed[y].push_back(XD(x,l));
    }
    dfs(0);
    /*
    for(i=0;i<n;i++){
    for(j=0;j<ed[i].size();j++)printf("%d->%d #%d\n",i,ed[i][j].y,j);
    }
    for(i=0;i<n;i++)printf("%d pre=%d prei=%d\n",i,pre[i],prei[i]);
    for(i=0;i<cyc.size();i++)printf("%d<-%d\n",ed[cyc[i].first][cyc[i].second].y,cyc[i].first);
    */
    cycc=cyc.size();
    for(i=0,j=cycc-1;i<j;i++,j--)swap(cyc[i],cyc[j]);
    for(i=0;i<cycc;i++){
    int r;
    long long tot=dfshei(cyc[i].first,-1,r,0,cyc[i].first);
    totd[cyc[i].first]=tot;
//  printf("%d %I64d\n",cyc[i].first,totd[cyc[i].first]);
    dfs2(cyc[i].first,-1,tot,r);
    }
    long long ctl=0;
    for(i=0;i<cycc;i++){
    cn[cyc[i].first]=i;
    cycl[i]=ed[cyc[i].first][cyc[i].second].l;
    ctl+=cycl[i];
//  printf("%d -(%d)> ",cyc[i].first,cycl[i]);
    }
//    puts("");
    j=0;
    long long cs=0;
    for(i=0;i<cycc;i++){
    while(cs<=ctl-cs){
        cs+=cycl[j];
        j++;
        if(j==cycc)j=0;
    }
    tt[i]=j;
    cs-=cycl[i];
//  printf("%d %d %d\n",i,cyc[i].first,tt[i]);
    }
    /*
    tots[0]=0;
    totlw[0]=0;
    totl[0]=0;
    for(i=0;i<cycc;i++){
    tots[i+1]=tots[i]+totd[cyc[i].first];
    totl[i+1]=totl[i]+cycl[i];
    totlw[i+1]=totlw[i]+totl[i]*dp[cyc[i].first];
    }*/
    for(i=0;i<n;i++){
    ans[i]+=(n-dp[root[i]])*tor[i];
    }
    long long ls=0;
    long long ll=0;
    long long dc=0;
    j=0;
    for(i=0;i<cycc;i++){
    // left half
    while((j+1)%cycc!=tt[i] || ll<0){
        int nj=(j==cycc-1?0:j+1);
        ll+=cycl[j];
        dc+=dp[cyc[nj].first];
        ls+=totd[cyc[nj].first]+ll*dp[cyc[nj].first];
        j=nj;
    }
    ansc[i]+=ls;
    ll-=cycl[i];
    ls-=totd[cyc[(i+1)%cycc].first]+cycl[i]*dc;
    dc-=dp[cyc[(i+1)%cycc].first];
    }
    j=cycc-1;
    ll=0;ls=0;dc=0;
    for(i=cycc-1;i>=0;i--){
    // right half
    while(j!=tt[i] || ll<0){
        int nj=(j==0?cycc-1:j-1);
        ll+=cycl[nj];
        dc+=dp[cyc[nj].first];
        ls+=totd[cyc[nj].first]+ll*dp[cyc[nj].first];
        j=nj;
    }
    ansc[i]+=ls;
    ll-=cycl[(i+cycc-1)%cycc];
    ls-=totd[cyc[(i+cycc-1)%cycc].first]+cycl[(i+cycc-1)%cycc]*dc;
    dc-=dp[cyc[(i+cycc-1)%cycc].first];
    }
    for(i=0;i<n;i++)ans[i]+=ansc[cn[root[i]]];

    for(i=0;i<n;i++)printf("%I64d%c",ans[i],(i==n-1)?'\n':' ');
}