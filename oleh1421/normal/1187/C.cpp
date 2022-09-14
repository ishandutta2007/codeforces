#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int t[200001];
int l[200001];
int r[200001];
int b[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>t[i]>>l[i]>>r[i];
    }
    for (int i=1;i<n;i++) b[i]=-1;
    for (int i=1;i<=m;i++){
        if (t[i]==0) continue;
        for (int j=l[i];j<r[i];j++){
            b[j]=1;
        }
    }
    for (int i=1;i<=m;i++){
        if (t[i]==1) continue;
        int minx=0;
        for (int j=l[i];j<r[i];j++){
            minx=min(minx,b[j]);
        }
        if (minx>=0){
            cout<<"NO";
            return 0;
        }
    }
    a[1]=10000;
    for (int i=2;i<=n;i++){
        a[i]=a[i-1]+b[i-1];
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}