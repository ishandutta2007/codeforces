#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int * a; int * b;
    a=new int[n-1];
    b=new int[n-1];
    for(int i=0;i<n-1;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) cin>>b[i];
    vector<int> ans;
    for(int j=0;j<=3;j++)
    {
        ans.clear();
        for(int i=0;i<n;i++)
        {

            if(i==0) ans.push_back(j);
            else
            {
                for(int k=0;k<=3;k++)
                {
                    if(((ans[i-1]|k)==a[i-1]) && ((ans[i-1]&k)==b[i-1]))
                    {


                        ans.push_back(k);
                        break;
                    }

                }
            }
            if(ans.size()<i+1) break;


        }
        if(ans.size()==n)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++) cout<<ans[i]<<" ";
            return 0;
        }


    }
    cout<<"NO";
    return 0;
}