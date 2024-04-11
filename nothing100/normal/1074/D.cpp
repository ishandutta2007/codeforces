#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int q,last;
map<int,pair<int,int> > f;
pair<int,int> get(int x){
    if (f[x].fi==0) return make_pair(x,0);
    pair<int,int> tmp=get(f[x].fi);
    f[x].fi=tmp.fi;
    f[x].se=tmp.se^f[x].se;
    return f[x];
}
int main(){
    scanf("%d",&q);
    for (int i=0;i<q;i++){
        int type,l,r,x;
        scanf("%d",&type);
        if (type==1){
            scanf("%d%d%d",&l,&r,&x);
            l^=last;
            r^=last;
            x^=last;
            if (l>r) swap(l,r);
            l+=1;
            r+=2;
            //printf("1 %d %d %d\n",l,r,x);
            pair<int,int> o,p;
            o=get(l);
            p=get(r);
            if (o.fi!=p.fi)
                f[p.fi]=make_pair(o.fi,o.se^p.se^x);
        }
        else if (type==2){
            scanf("%d%d",&l,&r);
            l^=last;
            r^=last;
            if (l>r) swap(l,r);
            l+=1;
            r+=2;
            pair<int,int> o,p;
            o=get(l);
            p=get(r);
            if (o.fi!=p.fi){
                printf("-1\n");
                last=1;
            }
            else{
                last=o.se^p.se;
                printf("%d\n",last);
            }
        }
    }
}