#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long long MAX_SIZE = 15000010; 
  
// isPrime[] : isPrime[i] is true if number is prime  
// prime[] : stores all prime number less than N 
// SPF[] that store smallest prime factor of number 
// [for Exp : smallest prime factor of '8' and '16' 
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ] 
vector<bool>isprime(MAX_SIZE , true); 
vector<int>prime; 
vector<int>SPF(MAX_SIZE); 

// function generate all prime number less then N in O(n) 
void manipulated_seive(int N) 
{ 
    // 0 and 1 are not prime 
    isprime[0] = isprime[1] = false ; 
  
    // Fill rest of the entries 
    for (long long int i=2; i<N ; i++) 
    { 
        // If isPrime[i] == True then i is 
        // prime number 
        if (isprime[i]) 
        { 
            // put i into prime[] vector 
            prime.push_back(i); 
  
            // A prime number is its own smallest 
            // prime factor 
            SPF[i] = i; 
        } 
  
        // Remove all multiples of  i*prime[j] which are 
        // not prime by making isPrime[i*prime[j]] = false 
        // and put smallest prime factor of i*Prime[j] as prime[j] 
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ] 
        // so smallest prime factor of '10' is '2' that is prime[j] ] 
        // this loop run only one time for number which are not prime 
        for (long long int j=0; 
             j < (int)prime.size() && 
             i*prime[j] < N && prime[j] <= SPF[i]; 
             j++) 
        { 
            isprime[i*prime[j]]=false; 
  
            // put smallest prime factor of i*prime[j] 
            SPF[i*prime[j]] = prime[j] ; 
        } 
    } 
} 

int gcd(int a,int b)
{
    while (b>0)
    {
        int tmp = a;
        a = b;
        b = tmp%b;
    }
    return a;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0;i<n;++i)
        cin >> A[i];
    
    manipulated_seive(MAX_SIZE);

    vector<int> counter(MAX_SIZE);

    int g = A[0];
    for (auto a: A)
        g = gcd(g,a);
    for (int i=0;i<n;++i)
        A[i]/=g;

    for (auto a:A)
    {
        while (a>1)
        {
            int p = SPF[a];
            counter[p]+=1;
            while (a%p==0)
            {
                a/=p;
            }
        }
    }

    int best_p = 0;
    int best_count = 1000000000;
    for (int i=0; i<MAX_SIZE; ++i)
    {
        if (n-counter[i]<best_count)
        {
            best_count = n-counter[i];
            best_p = i;
        }
    }
    if (best_p==0)
    {
        cout << "-1";
    }else
    {
        cout << best_count << endl;
    }

}