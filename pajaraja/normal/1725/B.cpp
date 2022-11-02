#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n;
int d;
int p[maxn];
int main() {
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++) {
        scanf("%d",&p[i]);
    }
    sort(p,p+n);
    int ans=0;
    int l=0;
    for(int i=n-1;i>=l;i--) {
        int tot=p[i];
        while(tot<=d && l<i) {
            tot+=p[i];
            l++;
        }
        if(tot>d) ans++;
    }
    printf("%d\n",ans);
    return 0;
}