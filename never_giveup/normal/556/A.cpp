#include <bits/stdc++.h>

using namespace std;
pair<int,int> q[200000];
int main()
{
    int n;
    string s;
    cin>>n>>s;
    if(n==1){
        cout<<1;
        return 0;
    }
    q[0].first=-1;
    q[0].second=1;
    q[n-1].second=-1;
    q[n-1].first=n-2;
    for(int i=1;i<n-1;i++)
       q[i]=make_pair(i-1,i+1);
    int i=0,ans=n;
    while(q[i].second!=-1){
        if(s[i]!=s[q[i].second]){
            ans-=2;
            q[q[i].first].second=q[q[i].second].second;
            q[q[q[i].second].second].first=q[i].first;
            if(q[i].first==-1)
                if(q[q[i].second].second==-1)
                    i=n-1;
                else
                    i=q[q[i].second].second;
            else
                i=q[i].first;
        }
        else{
            i=q[i].second;
        }
    }
    cout<<ans;
}