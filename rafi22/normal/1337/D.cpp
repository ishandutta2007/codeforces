#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        set <long long> red;
        set <long long> green;
        set <long long> blue;
        long long r,g,b,a;
        cin>>r>>g>>b;
        for(int i=0;i<r;i++)
        {
            cin>>a;
            red.insert(a);
        }
        for(int i=0;i<g;i++)
        {
            cin>>a;
            green.insert(a);
        }
        for(int i=0;i<b;i++)
        {
            cin>>a;
            blue.insert(a);
        }
        blue.insert(1000000007);
        blue.insert(0);
        red.insert(1000000007);
        red.insert(0);
        green.insert(1000000007);
        green.insert(0);
        long long ans=2000000000000000007;
        long long st,nd,rd;
        set <long long>::iterator it=red.begin(),it1;
        for(;it!=red.end();it++)
        {
            st=*it;
            it1=green.upper_bound(st);
            it1--;
            nd=*it1;
            it1=blue.lower_bound(nd);
            rd=*it1;
            if(st!=1000000007&&nd!=1000000007&&rd!=1000000007&&st!=0&&nd!=0&&rd!=0)
                ans=min(ans,(st-nd)*(st-nd)+(st-rd)*(st-rd)+(nd-rd)*(nd-rd));
            it1=blue.upper_bound(st);
            it1--;
            nd=*it1;
            it1=green.lower_bound(nd);
            rd=*it1;
            if(st!=1000000007&&nd!=1000000007&&rd!=1000000007&&st!=0&&nd!=0&&rd!=0)
                ans=min(ans,(st-nd)*(st-nd)+(st-rd)*(st-rd)+(nd-rd)*(nd-rd));
        }
        it=green.begin();
        for(;it!=green.end();it++)
        {
            st=*it;
            it1=red.upper_bound(st);
            it1--;
            nd=*it1;
            it1=blue.lower_bound(nd);
            rd=*it1;
            if(st!=1000000007&&nd!=1000000007&&rd!=1000000007&&st!=0&&nd!=0&&rd!=0)
                ans=min(ans,(st-nd)*(st-nd)+(st-rd)*(st-rd)+(nd-rd)*(nd-rd));
            it1=blue.upper_bound(st);
            it1--;
            nd=*it1;
            it1=red.lower_bound(nd);
            rd=*it1;
            if(st!=1000000007&&nd!=1000000007&&rd!=1000000007&&st!=0&&nd!=0&&rd!=0)
                ans=min(ans,(st-nd)*(st-nd)+(st-rd)*(st-rd)+(nd-rd)*(nd-rd));
        }
        it=blue.begin();
        for(;it!=blue.end();it++)
        {
            st=*it;
            it1=red.upper_bound(st);
            it1--;
            nd=*it1;
            it1=green.lower_bound(nd);
            rd=*it1;
            if(st!=1000000007&&nd!=1000000007&&rd!=1000000007&&st!=0&&nd!=0&&rd!=0)
                ans=min(ans,(st-nd)*(st-nd)+(st-rd)*(st-rd)+(nd-rd)*(nd-rd));
            it1=green.upper_bound(st);
            it1--;
            nd=*it1;
            it1=red.lower_bound(nd);
            rd=*it1;
           // cout<<st<<" "<<nd<<" "<<rd<<endl;
            if(st!=1000000007&&nd!=1000000007&&rd!=1000000007&&st!=0&&nd!=0&&rd!=0)
                ans=min(ans,(st-nd)*(st-nd)+(st-rd)*(st-rd)+(nd-rd)*(nd-rd));
        }
        cout<<ans<<endl;
    }
    return 0;
}