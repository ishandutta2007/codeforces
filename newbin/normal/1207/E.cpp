#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"?";
    for(int i = 0; i < 100; ++i) cout<<" "<<i;cout<<endl;
    cout<<"?";for(int i = 1; i <= 100; ++i) cout<<" "<<128*i;cout<<endl;
    int x,y;cin>>x>>y;
    cout<<"! "<<x/128*128+y%128<<endl;
}