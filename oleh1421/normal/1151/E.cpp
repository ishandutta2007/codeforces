#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int last=0;
    int res=0;
    for (int i=1;i<=n;i++){
        int cur;cin>>cur;
        if (cur>=last){
            res+=(n-cur+1ll)*(cur-last);
        } else {
            res+=cur*(last-cur)*1ll;
        }
        last=cur;
    }
    cout<<res;
    return 0;
}
//2 6 -2 -6  2