#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

int ask(int x)
{
    cout << "? " << x << endl;
    cin >> x;
    return x;
}

const int N = 1e5 + 10;
int mp[N];

signed main()
{
    int n,k;
    cin >> n >> k;
    
    int st = -1;
    int num = -1;
    
    while(1)
    {
        st = getRand(1,n);
        num = ask(st);
        
        if(num != k) break;
    }
    
    if(num > k)
    {
        while(1)
        {
            st--;
            if(st == 0) st = n;
            
            if(ask(st) == k)
            {
                cout <<"! " << st << endl;
                exit(0);
            }
        }
    }
    else
    {
        while(1)
        {
            st++;
            if(st == n+1) st = 1;
            
            if(ask(st) == k)
            {
                cout <<"! " << st << endl;
                exit(0);
            }
        }
    }
    
}