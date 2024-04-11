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
int ti[101000],xi[101000];
vector<int> tt[10100];
int vt[10100],vtid=0;
vector<int> allx;
int ans[101000];
int main(){
    int n,m,i,j,np;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d%d",&ti[i],&xi[i]);
    int t=0;
    for(np=0;np<n;np+=m){
        allx.clear();
        vtid++;
        for(j=np;j<np+m&&j<n;j++){
            t=max(t,ti[j]);
            int x=xi[j];
            if(vt[x]!=vtid){
                vt[x]=vtid;
                tt[x].clear();
                allx.push_back(x);
            }
            tt[x].push_back(j);
        }
        sort(allx.begin(),allx.end());
        int px=0;
        for(i=0;i<allx.size();i++){
            int x=allx[i];
            t+=x-px;
            for(j=0;j<tt[x].size();j++)ans[tt[x][j]]=t;
            t+=tt[x].size()/2+1;
            px=x;
        }
        t+=px;
    }
    for(i=0;i<n;i++)printf("%d%c",ans[i],(i==n-1?'\n':' '));
}