#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check(char * a,int c,int n)
{
    int akt=0;
    int i=0;
    while(i<n && akt<c)
    {
        akt+=(a[i]-48);
        i++;
        if(akt>c) return false;
        if(akt==c) akt=0;
    }
    return true;
}

int main()
{
    int n,d,m;
    cin>>n>>d>>m;
    for(int i=0;i<m;i++)
    {
        int x; int y;
        cin>>x>>y;
        int b=y-x;
        int c=y+x;
        if(b>=-d && b<=d && c>=d && c<=(2*n-d)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


}