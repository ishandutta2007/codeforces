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
    long long int n,m;
    cin>>n>>m;
    
    long long int dif[n];
    long long int min = 0;
    long long int max = 0;
    for(long long int i=0;i<n;i++)
    {
        long long int x,y;
        cin>>x>>y;
        dif[i] = x-y;
        min += y;
        max+= x;
    }
    
    if(m>=max)
    {
        cout<<"0"<<endl;
        return 0;
    }
    if(m<min)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    
    sort(dif, dif+n);
    long long int answer = 0;
    long long int val = n-1;
    while(max>m)
    {
        max -= dif[val];
        answer++;
        val--;
    }
    cout<<answer<<endl;
    
    return 0;
}