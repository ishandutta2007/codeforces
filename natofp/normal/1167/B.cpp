#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int a,b,c,d;
    vector<int> res(7,0);
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    cin>>a;
    cout<<"? 2 3"<<endl;
    fflush(stdout);
    cin>>b;
    cout<<"? 3 4"<<endl;
    fflush(stdout);
    cin>>c;
    cout<<"? 4 5"<<endl;
    fflush(stdout);
    cin>>d;
    if(a%23!=0 && b%23!=0 && c%23!=0 && d%23!=0)
    {
        res[6]=23;
        if(a%5==0 && b%5!=0)
        {
            res[1]=15;
            res[2]=a/res[1];
            res[3]=b/res[2];
            res[4]=c/res[3];
            res[5]=d/res[4];
        }
        else if(a%5==0 && b%5==0)
        {
            res[2]=15;
            res[1]=a/15;
            res[3]=b/15;
            res[4]=c/res[3];
            res[5]=d/res[4];
        }
        else if(b%5==0 && c%5==0)
        {
            res[3]=15;
            res[2]=b/15;
            res[1]=a/res[2];
            res[4]=c/15;
            res[5]=d/res[4];
        }
        else if(c%5==0 && d%5==0)
        {
            res[4]=15;
            res[5]=d/15;
            res[3]=c/15;
            res[2]=b/res[3];
            res[1]=a/res[2];
        }
        else
        {
            res[5]=15;
            res[4]=d/res[5];
            res[3]=c/res[4];
            res[2]=b/res[3];
            res[1]=a/res[2];
        }
    }
    else
    {
        if(a%23==0 && b%23!=0)
        {
            res[1]=23;
            res[2]=a/res[1];
            res[3]=b/res[2];
            res[4]=c/res[3];
            res[5]=d/res[4];
        }
        else if(a%23==0 && b%23==0)
        {
            res[2]=23;
            res[1]=a/23;
            res[3]=b/23;
            res[4]=c/res[3];
            res[5]=d/res[4];
        }
        else if(b%23==0 && c%23==0)
        {
            res[3]=23;
            res[2]=b/23;
            res[1]=a/res[2];
            res[4]=c/23;
            res[5]=d/res[4];
        }
        else if(c%23==0 && d%23==0)
        {
            res[4]=23;
            res[5]=d/23;
            res[3]=c/23;
            res[2]=b/res[3];
            res[1]=a/res[2];
        }
        else
        {
            res[5]=23;
            res[4]=d/res[5];
            res[3]=c/res[4];
            res[2]=b/res[3];
            res[1]=a/res[2];
        }
        vector<int> xd;
        xd.push_back(4);
        xd.push_back(8);
        xd.push_back(15);
        xd.push_back(16);
        xd.push_back(23);
        xd.push_back(42);
        for(int i=0;i<6;i++)
        {
            int val=xd[i];
            bool ok = true;
            for(int j=1;j<=6;j++)
            {
                if(res[j]==val) ok = false;
            }
            if(ok) res[6]=val;
        }
    }
    cout<<"! ";
    for(int i=1;i<=6;i++) cout<<res[i]<<" ";
    cout<<endl;
    fflush(stdout);

    return 0;
}