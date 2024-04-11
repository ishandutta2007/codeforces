#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n,ans=0;
    map<int,int> q;
    cin>>n;
    for(int i=1;i<n;i++){
        char c;
        cin>>c;
        q[c-'a']++;
        cin>>c;
        if(q[c-'A']==0)
            ans++;
        else
            q[c-'A']--;
    }
    cout<<ans;
}