#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
int a[101];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i=0;i<4;i++) cin>>a[i];
    sort(a,a+4);
    for (int i=0;i<16;i++){
        int sum0=0;
        int sum1=0;
        for (int j=0;j<4;j++){
            if ((1<<j)&i) sum0+=a[j];
            else sum1+=a[j];
        }
        if (sum0==sum1){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}