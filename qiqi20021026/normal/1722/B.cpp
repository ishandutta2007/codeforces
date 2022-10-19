#include<bits/stdc++.h>

using namespace std;

int main(){
    int T; cin>>T;
    while (T--){
        int n; string s1,s2;
        cin>>n>>s1>>s2;
        bool flag=1;
        for (int i=0;i<n;++i){
            if ((s1[i]=='R')!=(s2[i]=='R')) flag=0;
        }
        cout<<(flag?"YES\n":"NO\n");
    }
}