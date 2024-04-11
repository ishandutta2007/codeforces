#include<bits/stdc++.h>
using namespace std;
int n,a[1010],b[1010],x[1010],y[1010];
map<pair<int,int>,int> ma;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
    for (int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]);
    for (int i=0;i<n-1;i++)
    for (int j=0;j<n;j++){
        ma[make_pair(a[i]+x[j],b[i]+y[j])]++;
    }
    for (int i=0;i<n;i++)
    if (ma[make_pair(a[n-1]+x[i],b[n-1]+y[i])]==n-1){
        printf("%d %d\n",a[n-1]+x[i],b[n-1]+y[i]);
        return 0;
    }
    return 0;
}