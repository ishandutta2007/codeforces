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
    int n;
    cin>>n;
    string one,two;
    cin>>two>>one;
    
    map<char,int> first;
    map<char,int> second;
    
    for(int i=0;i<n;i++)
    {
        first[one[i]]++;
        second[two[i]]++;
    }
    for(int i=0;i<26;i++)
    {
        char x =(char) ('a'+i);
        if(first[x]!=second[x])
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    
    vector<int> moves;
    int answer = 0;
    
    for(int i=0;i<n;i++)
    {
        if(one[i]==two[i])
        {
            continue;
        }
        
        char x = one[i];
        int index = 0;
        for(int j=i+1;j<n;j++)
        {
            if(two[j]==x)
            {
                index = j;
                break;
            }
        }
        for(int j=index-1;j>=i;j--)
        {
            moves.push_back(j+1);
            char temp = two[j];
            two[j] = two[j+1];
            two[j+1] = temp;
        }
    }
    
    cout<<moves.size()<<endl;
    for(int i=0;i<moves.size();i++)
    {
        cout<<moves[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}