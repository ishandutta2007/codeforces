#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
vector<P> ret;

void merge(int l,int r) {
    if (l==r) {
        return;
    }
    int mid=(l+r)/2;
    merge(l,mid);
    merge(mid+1,r);
    for(int i=l;i<=mid;i++) {
        ret.push_back(P(i,i+r-mid));
    }
}

int main(void) {
    int n;
    scanf("%d",&n);
    int val=1;
    while (val*2<=n) {
        val*=2;
    }
    merge(1,val);
    merge(n-val+1,n);
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size();i++) {
        printf("%d %d\n",ret[i].first,ret[i].second);
    }
}