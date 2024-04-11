#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
int n, q;
LL a[100010], sums[100010], one;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for (int i=1; i<=n; i++) sums[i]=sums[i-1]+a[i-1];
    for (int i=1; i<n; i++) one+=sums[i];

    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        int k;
        scanf("%d", &k);
        LL p=n, ans=0, x=1, d=0;
        if (k==1) {
            ans=one;
        } else {
            for (;x>0;) {
                ans+=(sums[p]-sums[max(p-x, 0LL)])*d;
                p-=x;
                if (p<=0) break;
                d++;
                x*=k;
            }
        }
        cout<<ans;
        if (i==q-1) { puts(""); } else { printf(" "); }
    }
    return 0;
}