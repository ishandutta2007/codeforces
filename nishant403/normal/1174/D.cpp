//**//<<//>>// PHIR SE UDD CHALA ...............................

//#pragma GCC optimize("Ofast") 

#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a-1;i>=b;i--)
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<long long,long long>>
#define sti set <int,greater<int>>
#define vstr vector<string>
#define all(k) k.begin(),k.end()
#define rall(k) k.rbegin(),k.rend()
#define stll set <long long,greater<long long>>
#define Mi map <int,int>
#define Mll map <long long,long long>
#define MOD 1000000007;
#define nl cout << endl;
#define speed ios :: sync_with_stdio(0); cin.tie(0); cout.tie(nullptr);
#define inout(input,output) freopen(input,"r",stdin); freopen(output,"w",stdout);

using namespace std;
using namespace std::chrono;

void printPair( pair<ll,ll> x )
{
    cout << x.F << " " << x.S << endl;  
}

bool spsort(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    // Use all(k) not rall;
    if(a.F != b.F)
        return (a.F > b.F); 
    else
        return (a.S < b.S);
    // 5 1
    // 5 2
    // 4 2
    // 4 4
    // 3 2
    // 3 8
} 

//**//<<//>>// GOD'S PLAN ...............................

bool isvowel(char a)
{
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='y' || a==')')
        return true;
    else
        return false;
}

int numofBits(ll x)
{
    return floor(log2(x));
}

ll primel=1000050; // 10^6
vb prime(primel,true);
//mp getans;
//vll getans(primel,0);

void getprime();

void AJM()
{
    ll n,x; cin >> n >> x;
    vll a;
    ll len=0,prev_xor=0;
    vb check(1<<n,false);
    check[0]=true;
    
    if(x < (1<<n)) check[x]=true;
    
    f(i,0,(1<<n))
    {
        if(check[i]) continue;
        a.pb(i); len++;
        check[i]=true;
        
        if((i^x) < (1<<n)) check[i^x]=true;
    }
    
    vector<int> A(len);
    
    if(len > 0)
    {
        //a is the prefix xor array of the required array , so we convert it back to the original array
        A[0] = a[0];
        for(int i=1;i<len;i++) A[i] = a[i]^a[i-1];
    }
    
    cout << len << endl;
    f(i,0,A.size()) 
    { 
        cout << A[i] << " "; 
        if((i+1)==A.size()) nl;
    } 
    return;
}

//**//<<//>>// KHAIRIYAT TO PUCHO .............................

int main()
{
    // inout("1input.txt","1output.txt");
    speed
    int t=1;
    // cin >> t;
    while(t--)
    {
        AJM();
    }
}

void getprime()
{
    ll a=primel;
    prime[0]=prime[1]=false;
    // getans[0]=getans[1]=0;
    // ll temp=0;
    for(ll p=2;(ll)(p*p)<=a;p++)
    {
        if (prime[p] == true) 
        {
            for(int i=(p*p);i<=a;i+=p)
                prime[i] = false;
        }
    }
    // f(i,2,a)
    // {
    //     if(prime[i]) temp++;
    //     getans[i]=temp;
    // }
}

// For t=10000
// 3761771 - without speed console
// 4977903 - with speed console
// 2999 - without speed input output
// 981 - with speed input output