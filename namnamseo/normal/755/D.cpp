#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

const int M = 2097152;

int tree[M<<1];

int rsum(int l,int r){
    l+=M; r+=M;
    int ret=0;
    while(l<=r){
        if(l%2==1)ret+=tree[l++];
        if(r%2==0)ret+=tree[r--];
        l>>=1; r>>=1;
    }
    return ret;
}

void upd(int pos){
    pos+=M;
    while(pos) ++tree[pos], pos>>=1;
}

int main()
{
    int n, k;
    read(n, k);
    if(k > n/2) k=n-k;
    int x=1;
    typedef long long ll;
    ll ans=1;
    for(int i=1; i<=n; ++i){
        int l=n+x-k+1;
        int r=n+x+k-1;
        if(l > n) l-=n, r-=n;
        ans += 1 + rsum(l, r);
        upd(x);
        upd(x+n);
        x=(x+k-1)%n + 1;
        printf("%I64d ", ans);
    }
    return 0;
}