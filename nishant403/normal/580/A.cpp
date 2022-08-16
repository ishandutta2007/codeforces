#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define pll pair<long long,long long>
#define vl vector<long> 

int main()
{
 fast;   
   ll n,temp=1,a=1;
    cin >> n ;
    ll prev,x;
    
    cin >> prev;
    
    f(i,n-1) {
        temp++;
        cin >> x;
        if(x < prev) temp=1;
        a=max(a,temp);
        prev=x;
    }

cout << a;
    }