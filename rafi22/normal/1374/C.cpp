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
        int n,res=0,act=0;
        cin>>n;
        string str;
        cin>>str;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(') act--;
            else act++;
            res=max(res,act);
        }
        cout<<res<<endl;


    }
    return 0;
}