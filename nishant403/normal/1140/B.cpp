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
#define N 


int main()
{
 fast;   
 
 string s;
  ll t;
    cin >> t;
    while(t--)
    {
        
        ll n,k,i,j,an=0;
        cin >> n;
        string s;
        cin >> s;
        
        int c1=0;
        int c2=0;
        
        f(i,n) if(s[i]=='<') c1++;
            else break;
            
         f(i,n) if(s[n-i-1]=='>') c2++;
            else break;
           
            cout << min(c1,c2) << "\n";
    }
    
    
    
    }