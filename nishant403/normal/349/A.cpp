#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define vi vector<int>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


signed main()
{
Fast;    
    
  int n,a=0,b=0,x;
    
    cin >> n;
    
  f(i,n)
  {
    cin >> x;  
    if(x==25) a++;
    else if(x==50)
    {
        if(a>0){a--;b++;}   
        else {cout << "NO"; return 0; }
    }
    else
    {
        
        if(a>0 && b>0){a--;b--;}
        else if(a>2) {a-=3;}
        else {cout << "NO"; return 0; }
    } 
  }
    
    cout << "YES";
}