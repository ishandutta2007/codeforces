#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int n,zero=0,answer=0;
    cin>>n;
    char c;
    if(n==1)
    {
        cin>>c;
        if(c=='0')
            cout<<"No";
        else
            cout<<"Yes";
        return 0;
    }
    
    int firstone=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(c=='0')
        {
            zero++;
        }
        else if(c=='1')
        {
            if(firstone==0)
            {
                firstone=1;
                if(zero>1)
                    answer=1;
                zero=0;
            }
            else
            {
                if(zero==0||zero>2)
                    answer=1;
                zero=0;
            }
        }
    }
    if(zero>=2)
        answer=1;
    
    
    if(answer==1)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}