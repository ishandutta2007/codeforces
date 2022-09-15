#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int cnt[15000001];
int a[3000001];
char used[15000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int g=a[1];
    for (int i=2;i<=n;i++) g=__gcd(g,a[i]);
    for (int i=1;i<=n;i++) {
            a[i]/=g,cnt[a[i]]++;
         //   cout<<a[i]<<" "<<cnt[a[i]]<<endl;
    }
    if (cnt[1]==n){
        cout<<-1;
        return 0;
    }
    int N=15000000;
    for (int i=2;i<=N;i++) used[i]=true;
    int res=n-1;
    for (int i=2;i<=N;i++){
        if (used[i]){
        int cur=0;
        for (int j=i;j<=N;j+=i){
            cur+=cnt[j];
            if (i!=j) used[j]=false;
        }
        res=min(res,n-cur);
        }
    }
    cout<<res;
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4