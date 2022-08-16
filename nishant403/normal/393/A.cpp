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
 map<char,int> mm;
    string s;
  cin >> s;  
  for(auto c : s) 
  {
      mm[c]++;
  }
    cout << min(min( (mm['n']-1)/2, mm['e']/3) ,min(mm['t'],mm['i']) );
    
    
}