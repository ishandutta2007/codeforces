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
        string str;
        cin>>str;
        long long ile=0,mn=100000007,it;
        long long res=0;
        for(long long i=0;i<str.size();i++)
        {
            if(str[i]=='+') ile++;
            else ile--;
            if(ile<mn)
            {
                if(ile<0)
                    res+=i+1;
                mn=ile;
            }
        }
        cout<<res+str.size()<<endl;

    }


    return 0;
}