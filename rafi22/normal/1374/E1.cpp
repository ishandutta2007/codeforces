#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    deque<long long> alice;
    deque <long long> bob;
    deque <long long> together;
    long long n,k,a,ans=0;
    char ch1,ch2;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a>>ch1>>ch2;
        if(ch1=='1'&&ch2=='1') together.push_back(a);
        else if(ch1=='1') alice.push_back(a);
        else if(ch2=='1') bob.push_back(a);
    }
    sort(alice.begin(),alice.end());
    sort(bob.begin(),bob.end());
    sort(together.begin(),together.end());
    if(together.size()+min(alice.size(),bob.size())<k)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<k;i++)
    {
        if(!(alice.size()==0||bob.size()==0))
        {
            if(together.size()==0)
            {
                ans+=alice[0]+bob[0];
                alice.pop_front();
                bob.pop_front();
            }
            else if(alice[0]+bob[0]<=together[0])
            {
                ans+=alice[0]+bob[0];
                alice.pop_front();
                bob.pop_front();
            }
            else
            {
                ans+=together[0];
                together.pop_front();
            }
        }
        else
        {
            ans+=together[0];
            together.pop_front();
        }
    }
    cout<<ans;

    return 0;
}