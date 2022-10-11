#include <bits/stdc++.h>
#define index(x,y) (x) + (y)*m

using ll = long long;
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    
    vector<char> A(n*m);

    for (int y = 0; y < n; ++y)
        for (int x = 0; x < m; ++x)
            cin >> A[index(x,y)];
    
    vector<int> same(n*m);
    for (int x = 0; x < m; ++x)
    {
        same[index(x,n-1)] = 1;
        for (int y = n-2; y >= 0; --y)
        {
            if (A[index(x,y)] == A[index(x,y+1)])
                same[index(x,y)] = 1 + same[index(x,y+1)];
            else
                same[index(x,y)] = 1;
        }
    }



    ll ways = 0;
    for (int thick = 1; thick <= n/3; ++thick)
    {
        vector<int> going(n*m);
        for (int y = 0; y + 3*thick <= n; ++y)
        {
            bool nice = same[index(0,y)] == thick && same[index(0,y+thick)] == thick && same[index(0,y+2*thick)] >= thick;
            going[index(0,y)] = nice;
        }
        for (int y = 0; y + 3*thick <= n; ++y)
        {
            for (int x = 1; x < m; ++x)
            {
                bool nice = same[index(x,y)] == thick && same[index(x,y+thick)] == thick && same[index(x,y+2*thick)] >= thick;
                if (nice && A[index(x,y)] == A[index(x-1,y)] && 
                            A[index(x,y+thick)] == A[index(x-1,y+thick)] && 
                            A[index(x,y+2*thick)] == A[index(x-1, y + 2*thick)])
                    going[index(x,y)] = going[index(x-1,y)] + 1;
                else
                    going[index(x,y)] = nice; 
            }
            
        }
        for (int i=0; i<n*m; ++i)
            ways += going[i];
    }
    cout << ways;
    
}