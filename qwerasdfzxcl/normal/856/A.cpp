#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[101], b[101];
bool chk[1001010];
vector<int> dist;

void solve(){
    for (int i=0;i<=1000000;i++) chk[i]=0;
    dist.clear();
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    sort(a, a+n);
    for (int i=n-1;i>=0;i--){
        for (int j=i-1;j>=0;j--) dist.push_back(a[i]-a[j]);
    }
    b[0]=1;
    for (int x:dist) if (x+1<=1000000) chk[x+1]=1;
    int pt1=2;
    for (int i=1;i<n;i++){
        while(pt1<=1000000 && chk[pt1]) pt1++;
        if (pt1>1000000) break;
        b[i]=pt1;
        for (int x:dist) if (x+pt1<=1000000) chk[x+pt1]=1;
        pt1++;
    }
    if (pt1>1000000) printf("NO\n");
    else{
        printf("YES\n");
        for (int i=0;i<n;i++) printf("%d ", b[i]);
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}