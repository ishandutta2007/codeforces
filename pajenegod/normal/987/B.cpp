#pragma GCC target("fpmath=sse,sse2")

// not my code https://codeforces.com/blog/entry/98173
 
// Hi! One day, you'll do it:)
#include <bits/stdc++.h>
using namespace std;
#pragma gcc optimize("Ofast")
#pragma gcc target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma gcc optimize("unroll-loops")
#define all(z)              (z).begin(), (z).end()       
#define int                 long long          
#define fi(n)               for(int i=0;i<n;i++)
#define fj(n)               for(int j=0;j<n;j++)
#define fk(n)               for(int k=0;k<n;k++) 
#define setp(x)	            fixed<<setprecision(x)  
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define mem(a,b)            memset(a,b,sizeof(a))
#define endl                "\n"
typedef long double ld;            const ld pi=3.141592653589;               const int mod = 1000000007;     const int INF = 9e18;                             
typedef pair<int, int> pii;        typedef vector<int> vi;                   typedef vector<pii> vpii;       typedef vector<vi> vvi;    
typedef set<int> si;               typedef set<pii> spi;                     typedef multiset<int> msl;      typedef vector<string> vs; 
vi primes,fibonacci;            int xorval(int n);
bool isPrime(int n);        void sieve(int N);
int lcm(int a,int b);       int poww(int n,int k);
int nCr(int n,int r);       int leap(int y);    
void fiboseries(int n);     int fiboN(int n);
string baseto10(string s,int b);
string basefrom10(string s,int b);
double dis_p(int x1,int y1,int x2,int y2);
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};    
string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
 
// USE stoll for string to integer 
// MAP,SET- for(auto i=s.begin();i!=s.end();i++) i->first
// (n & ~n) returns rightmost 1 bit in n  || s.find==-1 means absent
// n<<i == n*(2^i)   while n>>i== n/(2^i)  CLosing side is used
// (<< - closed left, shifts bits to left(*2)), (>>  shifts right (/2))
// When n%n==n, use (n-1)%n +1 == n (1487B)
// 279C (calc no. from back of curay,q=0;; q+=(p*ar[i]); p*=10; )
// Max GCD is (a-b) and max when a,a/2 --> a/2 is max 
// Copy vector by '=' //MAP,SET-  auto(address is not int)
// INTERACTIVE: use flush between cout and cin: cout--flush--cin
 
// CODE STARTS (TEMPLATE FUCNTIONS ARE BELOW THE MAIN FUCNTIONS)
// JAI SHREE RAM!
 
void sweetheart()
{
    int n;  cin>>n;
    int m;  cin>>m;
    double n1=n*log(m);
    double m1=m*log(n);
    //if(n!=5 && m!=3 ) cout<<n1<<" "<<m1<<" ";
    if(n1<m1) cout<<">";
    else if(n1>m1) cout<<"<";
    else cout<<"=";
}
 
///////// MAIN FUNCTION ///////////////////////////////////////////
int32_t main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);    cout.tie(0);  cerr.tie(0);
    string jaaneman = "1";
    //getline(cin, jaaneman);
    int me = stoll(jaaneman);    int you = 0;
    while ((you++) < me)    {
        //cout<<"Case #"<<al<<": ";
        sweetheart();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
 
//CODE BELOW FOR TEMPLATE FUNCTIONS (Changed at 1520 F1)
bool isPrime(int n) {
    if (n<=1)               return 0;
    if (n<=3)               return 1;
    if (n%2==0 || n%3==0)   return 0;
    for (auto i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
    return 0;
    return 1;
}
void sieve(int N){
vi check(N+1);
for (int i=2;i<=N;i++) {
    if (!check[i]) 
    check[i] = i,primes.push_back(i);
    for (int j=0;j<primes.size() && primes[j]<=check[i] && i*primes[j]<=N;j++) 
    check[i * primes[j]] = primes[j];   }   
}
double dis_p(int x1, int y1, int x2, int y2)    { 
    double distance = sqrt((x1 - y1)*(x1 - y1) + (x2 - y2)*(x2 - y2));
    return distance;
}  
int lcm(int a, int b){
    return ((a * b) / lcm(a, b));       }
int poww(int n, int k)   { 
    int x=1;   //if mod (mod on 13th line)
    while (k)   {
        if (k & 1)   
		{ x*= n; x%=mod; }
        n*=n;
		n%=mod;
        k>>=1;
    }
    return x;
}   //multi n^k
int nCr(int n, int r) { // n C r efficient
    if(r>n) return 0;
    if(r>n-r) r=n-r;
    int res=1;
    for(int i=1;i<=r;i++) {
        res*=(n-r+i);
        res/=i;
    }
    return res;     //pass another var if mod is needed
}
void fiboseries(int n){   
    fibonacci.push_back(0);     fibonacci.push_back(1);
    int c1=0,c2=1;  int c3=c1+c2;
    while(c2<n) {
        c3=c1+c2;   c1=c2;      c2=c3;
        fibonacci.push_back(c3);      
    }// Series upto N, NOT N numbers
}
int fiboN(int n)
{   
    if(n<=1) return n;
    return fiboN(n-1) + fiboN(n-2);
}   //pass N+1 as indexing starts from 0
string baseto10(string s, int b) {
    int num=0; 
    fi(s.size()){
        if(isdigit(s[i]))
        num=num*b+(s[i]-'0');
        else 
        num=num*b+(s[i]-'A'+10);
    }
    return to_string(num);
} 
string basefrom10(string s,int b) {
    string num; 
    int n=stoll(s);
    while(n) {
        int x=n%b;  n/=b;
        if(x<10)
        num+=char('0'+x);
        else 
        num+=char('A'+x-10);
    }
    reverse(all(num));
    return num;
}
int leap(int y) {
    if (y%400 == 0)         return 1;
    else if (y%100 == 0)    return 0;
    else if (y%4 == 0)      return 1;
    else                    return 0;
}
int xorval(int n){
    if (n%4==0)             return n; //0,4,8,12
    else if (n%4==1)        return 1; //1,5,9
    else if (n%4==2)        return n+1; //2,6,10
    return 0;
}