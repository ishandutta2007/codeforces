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
#define all(x) x.begin(),x.end()

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    
    return true;
}

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    
    return true;
}

set<int> primes;

//maximum integers x so that x^i <= 10^18 
int lim[61] = {0,1000000000000000000,1000000000,1000000,31623,3982,1000,373,178,100,67,46,33,25,20,16,13,11,10,9,8,7,6,6,5,5,5,4,4,4,4,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};

//return n^k , it is guaranteed to fit in the long long and n > 1
int pw(int n,int k)
{
    int res = 1;
    while(k--) res*=n;
    return res;
}

//return a number p s.t p^k = x and p is prime, if exists
int find(int x,int k)
{
    int l = 2;
    int r = lim[k];
    int res = -1;
    
    while(l <= r)
    {
        int mid = (l + r)/2;
        
        if(pw(mid,k) <= x)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    
    if(pw(res,k) != x) return -1;
    
    if(!MillerRabin(res)) return -1;
    
    return res;
}

//Return a prime p if x = p^k
int primer(int x)
{
    int res = -1;
    
    for(int i=1;i<=60;i++)
    {
        res = find(x,i);
        if(res != -1) break;
    }
    
    return res;
}

//return -1 if x contains some other prime
//else return number of primes 

int make(int x)
{
    int cc = 0;
    
    for(auto v : primes)
    {
        if(x % v == 0)
        {
            cc++;   
            while(x % v == 0) x/=v;
        }
    }
    
    if(x != 1) return -1;
    return cc;
}

bool cmp(vector<int> & x1,vector<int> & x2)
{
    return (int)x1.size() > (int)x2.size();
}

signed main()
{
    fast;
    
    int n,k;
    cin >> n >> k;
    
    if(k == 1)
    {
        cout << 0;
        return 0;
    }
    
    map<int,vector<int> > pm;
   
    int x,y;
    
    f(i,n)
    {
       cin >> x;   
       pm[primer(x)].pb(x);
    }
    
    vector<vi> go;
    vector<pii> composite;
    
    for(auto x : pm)
    {
        if(x.F == -1) continue;
        
        if(x.S.size() > 1)
        {
            go.pb(x.S);
            primes.insert(x.F);
        }
    }
    
    for(auto  x : pm)
    {
        if(x.F == -1)
        {
            for(auto g : x.S)
            {
                int cc = make(g);
                if(cc != -1) composite.pb({cc,g});
            }
        }
    }
    
    //sort go by sizes
    sort(all(go),cmp);
    sort(all(composite));
    
    set<int> res;     
    int flag = 0;
    int last = -1;
    
    for(auto x : go)
    {
        for(auto y : x) 
        {
            if(res.size() < k)
            {
                if(y == x[0]) flag = 1;
                else flag = 0;
                
                res.insert(y);
                last = y;
            }
        }
    }
    
    //if the last prime we inserted was single then we try to fix    
    if(flag)
    {
        assert((int)res.size() == k);
        
        if(go.size() > 0 && go[0].size() > 2) 
        {
            //now we add the remaining prime and erase the first integer
            int gg = -1;
            
            for(auto x : go)
                for(auto y : x)
                  if(res.find(y) == res.end())
                    if(gg == -1) gg = y;
                
            res.insert(gg);
            res.erase(go[0][0]); 
        }
        else   
        {
            //first add a composite and then the primes according to it
            //and then some other primes 
            
            if(composite.size() == 0)
            {
                cout << 0;
                return 0;
            }
            
            res.clear();
            res.insert(composite[0].S);
            
            for(auto x : pm)
            {
                if(x.F == -1) continue;
                
                if(x.S.size() == 1) continue;
                
                if(composite[0].S % x.F != 0) continue;
                
                for(auto y : x.S) res.insert(y);
            }
            
            if(res.size() > k)
            {
                cout << 0;
                return 0;
            }
            
            for(auto x : go)
               for(auto y : x)
                 if(res.size() < k) res.insert(y);
        }
    }
    
    for(auto x : composite)
            if(res.size() < k) res.insert(x.second);
        
    if(res.size() < k) cout << 0;    
    else for(auto x : res) cout << x << ' ';   
}