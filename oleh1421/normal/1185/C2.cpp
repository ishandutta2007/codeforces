#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int cnt[111];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        m-=a[i];
        int sum=0;
        int res=0;
        for (int j=1;j<=100;j++){
            int add=(m-sum)/j;
            add=min(add,cnt[j]);
            sum+=add*j;
            res+=cnt[j]-add;
        }
        m+=a[i];
        cnt[a[i]]++;
        cout<<res<<" ";
    }
    return 0;
}