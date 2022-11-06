#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int h,q;

struct range {
    ll l,r;
};

ll max(ll a,ll b){return a>b?a:b; }
ll min(ll a,ll b){return a<b?a:b; }

range join(range a,range b){
    return {max(a.l,b.l), min(a.r,b.r)};
}

range level(int l){
    return {1LL<<(l-1), (1LL<<l)-1};
}

int nqn;

range ans, noq[100010];

ll cord[200010];
int cn;

int nopr[200010];

void in(){
    scanf("%d%d",&h,&q);
    ans=level(h);
    int i;
    int lv;
    ll a,b;
    int av;
    for(i=0;i<q;++i){
        scanf("%d %I64d %I64d %d",&lv,&a,&b,&av);
        
        while(lv<h){ a*=2; b*=2; ++b; ++lv; }
        if(av) ans=join(ans,{a,b});
        else noq[nqn++]={a,b};
    }
}

int main()
{
    int i;
    in();
    int a,b;
    if(ans.l>ans.r){ puts("Game cheated!"); return 0;}
    cord[cn++]=1LL<<(h-1);
    cord[cn++]=(1LL<<h);
    cord[cn++]=ans.l;
    cord[cn++]=ans.r+1;
    for(i=0;i<nqn;++i) cord[cn++]=noq[i].l, cord[cn++]=noq[i].r+1;
    sort(cord,cord+cn); cn=unique(cord,cord+cn)-cord;
    for(i=0;i<nqn;++i){
        ++nopr[lower_bound(cord,cord+cn,noq[i].l)-cord];
        --nopr[lower_bound(cord,cord+cn,noq[i].r+1)-cord];
    }
    for(i=1;i<cn;++i) nopr[i]+=nopr[i-1];
    a=lower_bound(cord,cord+cn,ans.l)-cord;
    b=lower_bound(cord,cord+cn,ans.r+1)-cord;
    int cnt=0, li;
    for(i=0;i<cn-1;++i){
        //printf("nopr[%d] : %d\n",i,nopr[i]);
        if(a<=i && i<b && !nopr[i]){
            ++cnt;
            li=i;
        }
    }
    if(cnt==1){
        if(cord[li+1]-cord[li]==1) printf("%I64d\n",cord[li]);
        else puts("Data not sufficient!");
    } else if(cnt==0) puts("Game cheated!");
    else puts("Data not sufficient!"); 
    return 0;
}