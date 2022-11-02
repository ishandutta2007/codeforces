#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
#define debug
using namespace std;

int v[maxn];
int bit[maxn];

void upd(int id,int s){
    id++;
    while(id < maxn){
        bit[id] += s;
        id += id&-id;
    }
}

int qry(int id){
    int ans = 0;
    id++;
    while(id){
        ans += bit[id];
        id -= id&-id;
    }
    return ans;
}

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
            v[i] = 1, upd(i,1);
    int l = 0, r = n-1, flip = 0;
    while(q--){
        int t;
        scanf("%d",&t);
        if(t == 2){
            int a,b;
            scanf("%d%d",&a,&b);
            if(!flip)
                printf("%d\n",qry(l+b-1)-qry(l+a-1));
            else
                printf("%d\n",qry(r-a)-qry(r-b));
        }
        else {
            int pos;
            scanf("%d",&pos);
            if(!flip){
                int t1 = pos, t2 = r-l+1-pos;
                if(t1 <= t2){
                    for(int i=l+pos-1,j=l+pos;i>=l;i--,j++){
                        v[j] += v[i];
                        upd(j,v[i]);
                    }
                    l += pos;
                }
                else {
                    for(int i=r-t2+1,j=r-t2;i<=r;i++,j--){
                        v[j] += v[i];
                        upd(j,v[i]);
                    }
                    r -= t2;
                    flip = 1;
                }
            }
            else {
                int t1 = pos, t2 = r-l+1-pos;
                if(t1 <= t2){
                    for(int i=r-pos+1,j=r-pos;i<=r;i++,j--){
                        v[j] += v[i];
                        upd(j,v[i]);
                    }
                    r -= pos;
                }
                else {
                    for(int i=l+t2-1,j=l+t2;i>=l;i--,j++){
                        v[j] += v[i];
                        upd(j,v[i]);
                    }
                    l += t2;
                    flip = 0;
                }
            }
        }
      //  for(int i=l;i<=r;i++)
        //    debug("%d ",v[i]);
        debug("   %d\n",flip);
    }
}