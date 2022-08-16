#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e7 + 10;

vector<int> go(N,-1);

void sieve()
{
    for(long long int i=2;i*i<N;i++)
        if(go[i] == -1)
           for(int j=i*i;j<N;j+=i) go[j] = i;
}

const int NN = 2e5 + 10;
int a[N];
pii res[N];

signed main()
{
    fast;
    
    sieve();
    
    int n;
    cin >> n;
    
    f(i,n) cin >> a[i];
    
    f(i,n)
    {
        if(go[a[i]] == -1)
        {
            res[i] = {-1,-1};
            continue;
        }
        
        int v = go[a[i]];
        int tmp = 1;
        
        while(a[i] % v == 0)
        {
            a[i]/=v; tmp*=v;
        }
        
        if(a[i] == 1) res[i] = {-1,-1};
        else res[i] = {a[i],tmp};
    }
    
    f(i,n) cout << res[i].F << ' ';
    cout << endl;
    f(i,n) cout << res[i].S << ' ';
}