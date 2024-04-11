#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int wskl=1;
    int wskp=n;
    int last=-1;
    vector<char> res;
    while(wskl<=wskp)
    {
        if(a[wskl]<=a[wskp])
        {
            if(a[wskl]>last)
            {
                last=a[wskl];
                wskl++;
                res.push_back('L');
            }
            else
            {
                if(a[wskp]>last)
                {
                    last=a[wskp];
                    wskp--;
                    res.push_back('R');
                }
                else break;
            }
        }
        else
        {
            if(a[wskp]>last)
            {
                last=a[wskp];
                wskp--;
                res.push_back('R');
            }
            else
            {
                if(a[wskl]>last)
                {
                    last=a[wskl];
                    wskl++;
                    res.push_back('L');
                }
                else break;
            }
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++) cout<<res[i];
    return 0;
}