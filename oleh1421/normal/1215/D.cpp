#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<n;i++){
        if (s[i]=='?') a[i+1]=-1;
        else a[i+1]=(s[i]-'0');
    }
    int sum1=0;
    int sum2=0;
    int cnt1=0;
    int cnt2=0;
    for (int i=1;i<=n/2;i++){
        if (a[i]!=-1) sum1+=a[i];
        else cnt1++;
    }
    for (int i=n/2+1;i<=n;i++){
        if (a[i]!=-1) sum2+=a[i];
        else cnt2++;
    }
    if (cnt1+cnt2==0){
        if (sum1==sum2) cout<<"Bicarp";
        else cout<<"Monocarp";
        return 0;
    }
    if (sum1+((cnt1-cnt2)/2)*9<=sum2 && sum2+((cnt2-cnt1)/2)*9<=sum1) cout<<"Bicarp";
    else cout<<"Monocarp";
    return 0;
}