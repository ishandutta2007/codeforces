#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2)
    {
        int x=abs(x1-x2)+1;
        int y=abs(y1-y2)+1;
        if(x1==x2) cout<<4+y*2<<endl;
        else if(y1==y2) cout<<4+x*2<<endl;
        else cout<<(x+y)*2<<endl;
    }
}