#include <bits/stdc++.h>
using namespace std;


string a[1005];
int n;

int main() {
    cin>>n;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        string cur="";
        for (int i=0;i<s.size();++i)
            if (!i || s[i]!=s[i-1]) cur+=s[i];
        a[i]=cur;
    }
    int ans=0;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        if (i==1 || a[i]!=a[i-1]) ++ans;
    cout<<ans;
}