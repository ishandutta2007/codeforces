#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        string str;
        cin>>str;
        int last1=-1,last2=-1,last3=-1,res=1000000007;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='1')
            {
                last1=i;
            }
            else if(str[i]=='2')
            {
                last2=i;
            }
            else
            {
                last3=i;
            }
            if(last1!=-1&&last2!=-1&&last3!=-1)
                res=min(res,i-min(last3,min(last1,last2))+1);
        }
        if(res==1000000007) cout<<0<<endl;
        else cout<<res<<endl;
    }
    return 0;
}