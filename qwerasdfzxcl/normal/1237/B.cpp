#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], b[100100], idx[100100];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int i=0;i<n;i++) scanf("%d", b+i);
    for (int i=0;i<n;i++) idx[a[i]]=i;
    int cur=1e9, ans=0;
    for (int i=n-1;i>=0;i--){
        if (idx[b[i]]>cur){
            ans++;
            //printf("%d\n", i);
        }
        cur=min(cur, idx[b[i]]);
    }
    printf("%d\n", ans);
    return 0;
}