// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// }}}

int in[101000];
int l[101000],r[101000];
int cnt[101000];
vector<int> qs[1010];
int ans[101000];
inline bool cmp(int a,int b){return r[a]<r[b];}
int qq;
int n;
inline void add(int x){
    if(x>n)return;
    if(cnt[x]==x)qq--;
    cnt[x]++;
    if(cnt[x]==x)qq++;
}
inline void del(int x){
    if(x>n)return;
    if(cnt[x]==x)qq--;
    cnt[x]--;
    if(cnt[x]==x)qq++;
}
int main(){
    int m,i,j,k;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    int sn=(int)(sqrt(n)+1);
    for(i=0;i<m;i++){
        scanf("%d%d",&l[i],&r[i]);
        l[i]--;r[i]--;
        qs[l[i]/sn].push_back(i);
    }
    for(i=0;i<=n/sn;i++){
        if(qs[i].size()==0)continue;
        sort(qs[i].begin(),qs[i].end(),cmp);
        memset(cnt,0,sizeof(cnt));
        qq=0;
        int ll=l[qs[i][0]],rr=r[qs[i][0]];
        for(j=ll;j<=rr;j++)add(in[j]);
        ans[qs[i][0]]=qq;
        for(j=1;j<qs[i].size();j++){
            int ii=qs[i][j];
            int lll=l[ii],rrr=r[ii];
            for(k=rr+1;k<=rrr;k++)add(in[k]);
            if(lll<ll){
                for(k=ll-1;k>=lll;k--)add(in[k]);
            }else if(lll>ll){
                for(k=ll;k<lll;k++)del(in[k]);
            }
            ll=lll;rr=rrr;
            ans[ii]=qq;
        }
    }
    for(i=0;i<m;i++)printf("%d\n",ans[i]);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread