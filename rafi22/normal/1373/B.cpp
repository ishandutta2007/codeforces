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
        int z=0,j=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='0') z++;
            else j++;
        }
        if(min(z,j)%2==0) cout<<"NET"<<endl;
        else cout<<"DA"<<endl;
    }


    return 0;
}