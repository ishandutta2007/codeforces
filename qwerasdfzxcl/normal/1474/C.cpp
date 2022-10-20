#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int curval, curmax, curc, n;
int a[2020];
bool chk[2020];
vector<pair<int, int>> rans;

bool check(){
    //printf("%d %d %d\n", curval, curmax, curc);
    for (;curmax>=0;curmax--) if (!chk[curmax]) break;
    if (curmax==-1){
        if (curc==n) return 1;
        else return 0;
    }
    int tmp=curval-a[curmax];
    int tidx=lower_bound(a, a+n, tmp)-a;
    if (a[tidx]!=tmp) return 0;
    for (;a[tidx]==tmp;tidx++) if (!chk[tidx]) break;
    if (a[tidx]!=tmp) return 0;
    curc += 2;
    chk[tidx]=1, chk[curmax]=1;
    curval=a[curmax];
    rans.push_back(make_pair(a[curmax], a[tidx]));
    return check();
}

void solve(){
    scanf("%d", &n);
    n *= 2;
    for (int i=0;i<2020;i++) a[i]=-1;
    for (int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a, a+n);
    bool ans=0;
    int i;
    for (i=0;i<n-1;i++){
        curval=a[n-1]+a[i];
        for (int j=0;j<n;j++) chk[j]=0;
        curc=0;
        curmax=n-1;
        rans.clear();
        if (check()){
            ans=1; break;
        }
    }
    if (ans){
        printf("YES\n");
        printf("%d\n", a[i]+a[n-1]);
        for (auto p:rans) printf("%d %d\n", p.first, p.second);
    }
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}