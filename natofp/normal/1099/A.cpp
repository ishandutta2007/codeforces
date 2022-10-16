#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int w,h; cin>>w>>h;
    int w1,d1; cin>>w1>>d1;
    int w2,d2; cin>>w2>>d2;
    for(int i=h;i>0;i--)
    {
        w+=i;
        if(i==d1) w=max(0,w-w1);
        if(i==d2) w=max(0,w-w2);
    }
    cout<<w;

    return 0;
}