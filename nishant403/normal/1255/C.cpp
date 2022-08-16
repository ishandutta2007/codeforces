#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
#define f(i,n) for(int i=0;i<n;i++)
#define F first
#define S second

vector< pair<int,int> > graph[N];
int freq[N];
bool used[N];

int main()
{
    int n,a,b,c;
    cin >> n;
    
    f(i,n-2)
    {
        cin >> a >> b >> c;
        freq[a]++;
        freq[b]++;
        freq[c]++;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
        graph[c].push_back({a,b});
    }
    
    int ans[n];
    
    //trivial case for first and second element
    
    for(int i=1;i<=n;i++)
    {
        if(freq[i] == 1) 
        {
            ans[0] = i;
            used[i] = 1;
            break;
        }
    }
    
    for(auto x : graph[ans[0]])
    {
        if(freq[x.F] == 2) ans[1] = x.F;
        if(freq[x.S] == 2) ans[1] = x.S;
    }
    
    used[ans[1]] = 1;
    
    for(int i=2;i<=n-1;i++)
    {
        int var = ans[i-1];
    
        for(auto x : graph[var])
        {
            if(used[x.F] == 1 && used[x.S] == 0) ans[i] = x.S;
            if(used[x.S] == 1 && used[x.F] == 0) ans[i] = x.F;
        }
        
        used[ans[i]] = 1;
    }
        
    for(int i=0;i<n;i++) cout << ans[i] <<" ";
}