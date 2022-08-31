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
 int k=0,n;   
 string s;   
 cin >> s;
    
 n=s.length();   
 for(auto z : s) if(z=='a') k++;   
 cout << min(2*k-1,n);   
}