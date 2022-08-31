#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>


signed main()
{
    int n;
    cin >> n;
    
    f(i,n)
    {
        f(j,n)
        {
            if(j % 2 == 0) cout << 0 << ' ';
            else cout << (1LL<<(i+j)) << " ";
        }
        
        cout << endl;
    }
    
    int q;
    cin >> q;
    
    int k;
    
    while(q--)
    {
        cin >> k;
        
        int x = 0;
        int y = 0;
        
        cout << x + 1 << ' ' << y + 1<< endl;
        
        while(!(x == n-1 && y == n-1))
        {
            if(y % 2 == 0)
            {
                if((k & (1LL<<(x+y+1)))) y++;
                else x++;
            }
            else if((k & (1LL<<(x+y+1)))) x++;
            else y++;
                
            cout << x+1 << ' ' << y+1 << endl;
        }
    } 
}