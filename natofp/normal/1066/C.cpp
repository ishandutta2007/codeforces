#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
int q; cin>>q;
map<int,int> a;
int l=1;
int r=0;
while(q--)
{
    char x; cin>>x;
    if(x=='L') {int t; cin>>t; a[t]=l++;}
    else if(x=='R') {int t; cin>>t; a[t]=r--;}
    else
    {
        int t; cin>>t;
        cout<<min(l-a[t],a[t]-r)-1<<endl;
    }
}

    return 0;
}