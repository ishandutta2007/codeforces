#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    vector<int> ans;
    int n=s.length();
    int lo=0;
    int hi=n-1;
    while(lo<hi)
    {
        //cout<<lo<<" "<<hi<<endl;
        int a=-1;
        int b=-1;
        while(lo<hi && s[lo]!='(')
        {
            lo++;
        }
        if(lo<hi && s[lo]=='(')
        {
            a=lo;
        }
        while(hi>lo && s[hi]!=')')
        {
            hi--;
        }
        if(hi>lo && s[hi]==')')
        {
            b=hi;
        }
        if(a!=-1 && b!=-1)
        {
            ans.push_back(a);
            ans.push_back(b);
            lo++; hi--;
        }
    }
    if(ans.size()==0)
    {
        cout<<0; return 0;
    }
    cout<<1<<endl;
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" ";
    return 0;
}