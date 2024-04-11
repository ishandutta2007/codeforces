#include<bits/stdc++.h>

using namespace std;

#define N 1000005
int n;
bitset<N> a,ans,tmp;
int main(){
    string s;
    cin>>n>>s;
    for (int i=0;i<n;++i){
        a[i]=s[i]-'0';
    }
    ans=a;
    auto cmp=[&](auto p,auto q)->bool
    {
        for (int i=0;i<n;++i){
            if (p[i]!=q[i]) return p[i]>q[i];
        }
        return 0;
    };
    for (int i=1;i<=30;++i){
        tmp=a|(a<<i);
        if (cmp(tmp,ans)) ans=tmp;
    }
    bool fl=0;
    for (int i=0;i<n;++i){
        if (fl|ans[i]) cout<<ans[i];
        fl|=ans[i];
    }
    if (!fl) cout<<0;
    cout<<'\n';
}