#include <bits/stdc++.h>
#define ll long long
#define maxn 200200
using namespace std;

int v[maxn];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
    sort(v,v+n);
    reverse(v,v+n);
    int ans = 1;
    int last = v[0];
    for(int i=1;i<n;i++){
        if(last > v[i]+k) ans++;
        else if(v[i] == last) ans++;
        if(v[i+1] != v[i]) last = v[i];
    }
    printf("%d\n",ans);
}