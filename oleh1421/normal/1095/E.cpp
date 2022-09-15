#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000003];
int s[1000003];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string st;cin>>st;
    for (int i=1;i<=n;i++){
        a[i]=(st[i-1]=='(')*2-1;
        s[i]=s[i-1]+a[i];
    }
    if (s[n]!=2 && s[n]!=-2){
        cout<<0;
    } else if (s[n]==2){
        int minx=0;
        for (int i=1;i<=n;i++) minx=min(minx,s[i]);
        if (minx<0){
            cout<<0;
        } else {
            int cnt=0;
            int index=0;
            for (int i=1;i<=n;i++){
                if (s[i]<2) index=i;
            }
            for (int i=index+1;i<=n;i++){
                if (a[i]==1 && s[i]-2>=0) cnt++;
            }
            cout<<cnt;
        }
    } else {
        int minx=0;
        for (int i=1;i<=n;i++) minx=min(minx,s[i]);
        if (minx<-2){
            cout<<0;
        } else {
            int index=n+1;
            for (int i=1;i<=n;i++){
                if (s[i]<0){
                    index=i;
                    break;
                }
            }
            int cnt=0;
            for (int i=1;i<=index;i++){
                 cnt+=(a[i]==-1);
            }
            cout<<cnt;

        }
    }
    return 0;
}
//2 6 -2 -6  2