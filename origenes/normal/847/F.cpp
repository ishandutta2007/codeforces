#include <iostream>
#include <algorithm>
using namespace std;
struct Candidate{
    int v, lst, index, state;
    bool operator < (const Candidate& rhs) const{
        if(v!=rhs.v) return v>rhs.v;
        return lst<rhs.lst;
    }
}c[110];
inline bool cmp(Candidate c1, Candidate c2){
    return c1.index<c2.index;
}
int n, k, m, a;
int main(){
    cin>>n>>k>>m>>a;
    for(int i=1; i<=n; i++){
        c[i].v=c[i].lst=0;
        c[i].index=i;
    }
    for(int i=1; i<=a; i++){
        int g;
        cin>>g;
        c[g].v++;
        c[g].lst=i;
    }
    int cur;
    sort(c+1, c+n+1);
    if(m==a){
        for(int i=1; i<=n; i++){
            if(i<=k&&c[i].v) c[i].state=1;
            else c[i].state=3;
        }
        /*for(int i=1; i<=min(k, m); i++)
            c[i].state=1;
        for(int i=min(k, m)+1; i<=n; i++)
            c[i].state=3;*/
        goto label;
    }
    if(n==k){
        for(int i=1; i<=n; i++){
            if(c[i].v) c[i].state=1;
            else c[i].state=2;
        }
        goto label;
    }
    cur=1;
    for(int i=1; i<=n; i++){
        int tot=m-a, cnt=k-i;
        bool flag=true;
        if(!c[i].v)
            goto label2;
        for(int j=i+1; j<=n; j++){
            if(cnt<0) break;
            if(tot<c[i].v-c[j].v+1){
                flag=false;
                break;
            }
            tot-=c[i].v-c[j].v+1;
            cnt--;
        }
        if(flag){
            label2:
            cur=i;
            break;
        }
        c[i].state=1;
    }
    for(int i=cur; i<=n; i++){
        if(i<=k||c[i].v+m-a>c[k].v) c[i].state=2;
        else c[i].state=3;
    }
    label:
    sort(c+1, c+n+1, cmp);
    for(int i=1; i<=n; i++)
        cout<<c[i].state<<' ';
    cout<<endl;
    return 0;
}