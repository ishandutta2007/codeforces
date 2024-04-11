#include <cstdio>
#include <algorithm>
using namespace std;
int data[1010];
int comp[1010], cn;
int cnt[1010];
int allcnt[1010];
int n;
bool eraseVal(int a){
    int x=lower_bound(comp, comp+cn, a)-comp;
    if(comp[x]!=a) return false;
    if(cnt[x] == allcnt[x]) return false;
    ++cnt[x];
    return true;
}
void increaseVal(int x){
    x=lower_bound(comp, comp+cn, x)-comp;
    --cnt[x];
}
int main()
{
    scanf("%d",&n);
    int i,j;
    int zc=0;
    for(i=0;i<n;++i){
        scanf("%d",data+i);
        comp[i]=data[i];
        if(data[i]==0) ++zc;
    }
    sort(data,data+n);
    sort(comp,comp+n);
    cn=unique(comp,comp+n)-comp;
    for(i=0;i<n;++i){
        ++allcnt[lower_bound(comp,comp+cn,data[i])-comp];
    }
    int ans=zc;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){ if(i==j) continue;
            int a=data[i], b=data[j], c;
            if(a==0 && b==0) continue;
            eraseVal(a);
            eraseVal(b);
            int cnt=2;
            while(true){
                c=a+b;
                a=b; b=c;
                if(abs(c)>int(1e9)) break;
                if(!eraseVal(c)) break;
                ++cnt;
            }
            ans=max(ans,cnt);
            a=data[i]; b=data[j];
            increaseVal(a);
            increaseVal(b);
            cnt-=2;
            while(cnt){
                c=a+b;
                a=b; b=c;
                increaseVal(c);
                --cnt;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}