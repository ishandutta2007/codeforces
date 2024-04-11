#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,val=0,sol;
        cin>>n;
        sol=n;
        cin>>val;
        for(int i=1;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            if(tmp!=val) sol=1;
        }
        cout<<sol<<endl;
    }
}