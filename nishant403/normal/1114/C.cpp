
#include <bits/stdc++.h>
using namespace std;

void factorize(unsigned long long n,vector<pair<unsigned long long int,unsigned long long int> > & fac) 
{ 
unsigned long long   int count = 0; 
  
    while (!(n % 2)) { 
        n >>= 1;  
        count++; 
    } 
  
    if (count) 
        fac.push_back(make_pair(2,count));
        
    for (unsigned long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            fac.push_back(make_pair(i,count));
    } 
  
    if (n > 2) 
        fac.push_back(make_pair(n,1));
} 

bool isprime(unsigned long long n)
{
    unsigned long long i;
    for(i=2;i<=(unsigned long long)sqrt(n);i++) if(n%i==0) return false;
    return true;
}


int main()
{
    unsigned long long n,b,temp,numb;
    vector<pair<unsigned long long int,unsigned long long int> > factors;

    cin >> n >> b;
    
    if(isprime(b))
    {
        factors.push_back(make_pair(b,1));
    }
    else factorize(b,factors);
    
   unsigned long long int powers[factors.size()];
  
    for(unsigned long long  i=0;i<factors.size();i++)
    {
        powers[i]=0;
        temp=n;
        numb=(factors[i].first);
        while(temp>=numb)
        {
            powers[i]+=temp/numb;
     temp/=numb;   
        }
        
        powers[i]=powers[i]/(factors[i].second);
    }
    
unsigned long long ans=powers[0];
  for(unsigned long long i=0;i<factors.size();i++) ans=min(ans,powers[i]);
  cout << ans;
    return 0;
}