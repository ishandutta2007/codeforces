#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;
vector<LL> ans;
int main(){
    scanf("%d",&n);
    for (int i=1;i*i<=n;i++){
        if (n%i==0){
            ans.push_back(1LL*i*(n/i-1)*(n/i)/2+n/i);
            if (i*i!=n) ans.push_back(1LL*n/i*(i-1)*i/2+i);
        }
    }
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
}