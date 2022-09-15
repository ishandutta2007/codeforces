#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int f[200001];
int cnt[200001];
int main()
{
    int n;cin>>n;
    int res=0;
    int maxx=0;
    for (int i=1;i<=n;i++){
        int color;cin>>color;
        cnt[f[color]]--;
        f[color]++;
        cnt[f[color]]++;
        maxx=max(maxx,f[color]);
        if (cnt[1]==i || cnt[i]==1 || (cnt[1]==1 && cnt[maxx]*maxx==i-1) || (cnt[maxx]==1 && cnt[maxx-1]*(maxx-1)==i-maxx)) res=i;
    }
    cout<<res;

    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4