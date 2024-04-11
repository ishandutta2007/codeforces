#include <cstdio>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

vector <int> a;

int  b(int lb,int ub,int x){
    int cur = (lb+ub)/2;

    if(a[cur]==x) return cur;
    if(lb==ub-1){
        if(x<a[lb]) return lb;
        return ub;
    }
    if(a[cur]>x) return b(lb,cur,x);
    if(a[cur]<x) return b(cur,ub,x);
}

int  b1(int lb,int ub,int x){
    int cur = (lb+ub)/2;
    //printf("BINARY:%d %d %d\n",x,a[cur],cur);
    if(a[cur]==x){
        //printf("BINARY:%d %d %d\n",x,a[cur],cur);
        return cur;
    }
    if(lb==ub-1) return 1000000007;
    if(a[cur]>x) return b1(lb,cur,x);
    if(a[cur]<x) return b1(cur,ub,x);
    return 1000000007;
}

typedef pair<int,int> pii;

int t[150005];
int q,n,z,l = 0;



int main(){
    scanf("%d %d %d",&n,&z,&q);
    for(int i = 0;i<n;i++)
        scanf("%d",&t[i]);
    if(n<z) z = n;
    for(int o = 0;o<q;o++){
        int id,x;
        scanf("%d %d",&x,&id);
        if(x==2){
            if(l==0){
                printf("NO\n");
                continue;
                //continue;
            }
            //printf("%d\n",b1(0,l,t[id-1]));
            int pos = b1(0,l,t[id-1]);
            if(pos!=1000000007 && pos>=l-z){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else{
            if(l==0){
                a.push_back(t[id-1]);
                l=1;
            }
            else {
            a.insert(a.begin()+b(0,l,t[id-1]),t[id-1]);
            l++;
            }
        }
    }


}