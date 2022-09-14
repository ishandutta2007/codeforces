#include <bits/stdc++.h>
typedef long long ll;
#define int long long
using namespace std;
int x[200001];
int c[200001];
int a[200001];
int32_t main()
{
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>x[i];
    int A;cin>>A;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++){
        a[i]=(max(0ll,x[i]-k)/A)+(max(0ll,x[i]-k)%A>0);
        a[i]=max(a[i],a[i-1]);
    }
    a[0]=0;
    int res=0;
    set<int>st;
    for (int i=1;i<=n;i++){
        st.insert(c[i]);
        if (a[i]>a[i-1]+(int)st.size()){
            cout<<-1;
            return 0;
        }
        for (int j=1;j<=a[i]-a[i-1];j++){
            res+=*st.begin();
            st.erase(st.begin());
        }
    }
    cout<<res;
    return 0;
}