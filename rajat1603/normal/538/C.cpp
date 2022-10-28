#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,m;
int d[N];
int h[N];
int main(){
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m;++i){
        cin>>d[i]>>h[i];
    }
    ans = h[1]+d[1]-1;
    ans = max(ans,h[m]+n-d[m]);
    for(int i=2;i<=m;++i){
        int dif = d[i] - d[i-1];
        dif -= abs(h[i]-h[i-1]);
        if(dif<0){
            printf("IMPOSSIBLE");
            return 0;
        }
        dif>>=1;
        ans = max(ans,max(h[i]+dif,h[i-1]+dif));
    }
    printf("%d\n",ans);
}