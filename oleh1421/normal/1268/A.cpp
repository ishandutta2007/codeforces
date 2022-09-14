#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007ll;
typedef long long ll;
using namespace std;
int a[300001];
int x[300001];
int b[300001];
int main()
{
    //freopen("meetings.in","r",stdin);
    //freopen("meetings.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=0;i<n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
    }
    for (int i=0;i<k;i++) x[i]=a[i];
    bool ok=true;
    for (int i=0;i<n;i++){
        if (x[i%k]<a[i]) ok=false;
        if (x[i%k]!=a[i]) break;
    }
    cout<<n<<endl;
    if (ok){
        for (int i=0;i<n;i++) cout<<x[i%k];
        return 0;
    }
    for (int i=k-1;i>=0;i--){
        if (x[i]<9){
            x[i]++;
            break;
        } else x[i]=0;
    }
    for (int i=0;i<n;i++) cout<<x[i%k];
    return 0;
}
/*
5
2 1 1 1 2 2 1 1 1 1
*/