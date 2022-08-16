#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int N = 1e5 + 10;
vector<int> isprime(N,1);
vector<int> primes;

void sieve()
{
  isprime[0] = isprime[1] = 0;

    for(int i=2;i<N;i++)
       if(isprime[i])
    {
        for(int j=i*i;j<N;j+=i) isprime[j] = 0;
        primes.pb(i);
    }
}

int op = 0;

int q(int x)
{
    op++;
    
    cout <<"A " << x << endl;
    cin >> x;
    return x;
}

int q2(int x)
{
    op++;
    
    cout <<"B " << x << endl;
    cin >> x;
    return x;
}

signed main()
{
    sieve();
    
    int n;
    cin >> n;
        
    int num = 1;
    
    vi go;
    
    vi big;
    
    for(auto x : primes)
    {
        if(x > n) break;
        
        if(x > 316) big.pb(x);
        else
        {
        q2(x);
        if(q(x) > 0) go.pb(x);
        }
    }
    
    for(auto x : go)
    {
        int v = x;
        num*=x;
        
        while((v*x) <= n)
        {
            v*=x;
            if(q(v) == 0) break;
            num*=x;
        }
    }
    
    int tot = 1 + (int)big.size();
    
    //atmost one prime from this 
    for(int i=0;i<big.size();i++)
    {
       if(q2(big[i]) > 1) num*=big[i];
        
       tot--; 
        
       if(i % 100 == 99 && q(1) == tot + 1 && num == 1)
       {
           //answer from last 100 primes
           for(int j=0;j<100;j++)
               if(q(big[j+i-99]))
           {
               num*=big[j+i-99];
               cout <<"C " << num << endl;
               return 0;
           }
       } 
    }
    
    int ss = min((int)big.size(),(int)100);
    
    //last 100 values left
    for(int i=0;i<ss;i++)
        if(q(big[(int)big.size()-i-1])) num*=big[(int)big.size()-i-1];
    
    cout << "C " << num << endl;
    
    return 0;
}