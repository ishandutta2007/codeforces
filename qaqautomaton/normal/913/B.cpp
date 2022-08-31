#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1024],cnt[1024],nleaf[1024];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;++i){
        scanf("%d",f+i);
        nleaf[f[i]]=1;
    }
    for(int i=n;i;--i){
        if(!nleaf[i])++cnt[f[i]];
        else if(cnt[i]<3){printf("No\n");return 0;}
    }
    
    printf("Yes\n");
    return 0;
}