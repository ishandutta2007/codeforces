#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[3][300300];
int n1, n2, n3;
ll anss[3];

ll check(int idx){
    ll ret=a[(idx+1)%3][0]+a[(idx+2)%3][0];
    ret=min(ret, min(anss[(idx+1)%3], anss[(idx+2)%3]));
    return ret;
}

int main(){
    scanf("%d %d %d", &n1, &n2, &n3);
    for (int i=0;i<n1;i++){
        scanf("%d", &a[0][i]);
        anss[0] += a[0][i];
    }
    for (int i=0;i<n2;i++){
        scanf("%d", &a[1][i]);
        anss[1] += a[1][i];
    }
    for (int i=0;i<n3;i++){
        scanf("%d", &a[2][i]);
        anss[2] += a[2][i];
    }
    sort(a[0], a[0]+n1);
    sort(a[1], a[1]+n2);
    sort(a[2], a[2]+n3);
    ll ans=check(0);
    for (int i=1;i<3;i++) ans=min(ans, check(i));
    printf("%lld\n", anss[0]+anss[1]+anss[2]-2*ans);
    return 0;
}