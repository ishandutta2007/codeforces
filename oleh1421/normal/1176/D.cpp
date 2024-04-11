#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int b[3000001];
int cnt[3000001];
bool used[3000001];
int p[3000001];
int main()
{
    int n;cin>>n;
    for (int i=1;i<=n+n;i++) cin>>b[i],cnt[b[i]]++;
    sort(b+1,b+n+n+1);
    reverse(b+1,b+n+n+1);
    int c=0;
    for (int i=2;i<=3000000;i++) used[i]=true;
    for (int i=2;i*i<=3000000;i++){
        if (!used[i]) continue;
        for (int j=i*i;j<=3000000;j+=i){
            used[j]=false;
        }
    }
    for (int i=2;i<=3000000;i++){
        if (used[i]) p[++c]=i;
    }
    for (int i=1;i<=n+n;i++){
        int x=b[i];
        if (cnt[x]<=0 || used[x]==1) continue;
        int j;
        for (j=2;x%j;j++){}
        cout<<x<<" ";;
        cnt[x]--;
        cnt[x/j]--;
    }
    for (int i=n+n;i>=1;i--){
        int x=b[i];
        if (cnt[x]>0){
            cout<<x<<" ";
            cnt[x]--;
            cnt[p[x]]--;
        }
    }
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4