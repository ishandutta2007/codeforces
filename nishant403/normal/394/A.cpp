#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 

int main()
{
 fast;   
    int a[3]={0},i;
    string s;
    cin >> s;
    int key=0;
    for(auto z : s)
    {
        if(z=='|') a[key]++;
        else key++;
    }
        
    bool flag=false;
    if(a[0]+a[1]==a[2]) flag=true;
    else if(a[0]+a[1]-a[2] == 2)
    {
     if(a[0]>1)a[0]--,a[2]++,flag=true; 
     else if(a[1]>1) a[1]--,a[2]++,flag=true;
    }
    
    else if(a[2]-(a[0]+a[1])==2) a[1]++,a[2]--,flag=true;
        
    if(flag)
    {
    f(i,a[0]) cout << '|';
    cout << '+';
    f(i,a[1]) cout << '|';
    cout << '=';
    f(i,a[2]) cout << '|';
    }   
     else cout << "Impossible";   
    
}