#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int t,n,x,y,d,ans;

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&x,&y,&d);
        ans=1<<30;
        if(x%d==y%d) ans=min(ans,abs(x-y)/d);
        if(y%d==1) ans=min(ans,(x-1)/d+bool((x-1)%d)+(y-1)/d);
        if(n%d==y%d) ans=min(ans,(n-x)/d+bool((n-x)%d)+(n-y)/d);
        if(ans!=1<<30) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}