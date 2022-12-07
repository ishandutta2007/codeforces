/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>m>>n;
    map<int,int> mp;
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        for(int j=l;j<=r;j++)
            mp[j]++;
    }
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)
            answer++;
    }
    cout<<answer<<endl;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}