#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int b[200001];
int c[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    multiset<int>st;
    for (int i=1;i<=n;i++) st.insert(b[i]);
    for (int i=1;i<=n;i++){
        auto it=st.lower_bound((n-a[i])%n);
        if (it!=st.end()){
            int x=(*st.lower_bound((n-a[i])%n));
            int y=(*st.begin());
            if ((x+a[i])%n<(y+a[i])%n){
                c[i]=x;
                st.erase(st.find(x));
            }  else {
                c[i]=y;
                st.erase(st.begin());
            }
            c[i]+=a[i];
            c[i]%=n;
        } else {
            c[i]=(a[i]+(*st.begin()))%n;
            st.erase(st.begin());
        }
    }
    for (int i=1;i<=n;i++) cout<<c[i]<<" ";
    return 0;
}