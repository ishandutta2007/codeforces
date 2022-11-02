#include<bits/stdc++.h>
using namespace std;
struct coupon{
    int l,r,id;
    bool operator <(const coupon &a) const{
        return (r<=a.r);
    }
}c[300010];
int cmp(coupon x,coupon y){
    return ((x.l<y.l)||((x.l==y.l)&&(x.r>y.r)));
}
multiset<coupon> que;
int n,m,ans;
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d%d",&c[i].l,&c[i].r);
        c[i].id=i+1;
    }
    sort(c,c+n,cmp);
    for (int i=0;i<n;i++){
        que.insert(c[i]);
        if (que.size()>m){
            multiset<coupon>::iterator it=que.begin();
            que.erase(it);
        }
        if (que.size()==m){
            multiset<coupon>::iterator it=que.begin();
            ans=max(ans,(it->r)-c[i].l+1);
        }
    }
    printf("%d\n",ans);
    if (ans){
        que.clear();
        for (int i=0;i<n;i++){
            que.insert(c[i]);
            if (que.size()>m){
                multiset<coupon>::iterator it=que.begin();
                que.erase(it);
            }
            if (que.size()==m){
                multiset<coupon>::iterator it=que.begin();
                if (((it->r)-c[i].l+1)==ans){
                    for (it=que.begin();it!=que.end();it++) cout<<it->id<<" ";
                    return 0;
                }
            }
        }
    }
    else{
        for (int i=1;i<=m;i++) printf("%d ",i);
    }
}