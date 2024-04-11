#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n,k,a[maxn];
long long p;

int calc(int u){
    long long ret=0;
    while (u>0){
        ret+=a[u-1];
        u-=k;
    }
    return ret;
}

int mid_search(int l,int r){
    if (l==r) return l;
    int md=(l+r)>>1;
    if (calc(md+1)<=p) return mid_search(md+1,r);
    else return mid_search(l,md);
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d%lld%d",&n,&p,&k);
        for (int i=0;i<n;++i) scanf("%d",&a[i]);
        sort(a,a+n);   
        printf("%d\n",mid_search(0,n));
    }
    return 0;
}