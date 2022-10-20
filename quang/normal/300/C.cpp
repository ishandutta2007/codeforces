#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY 1000000007
#define LIMIT 1000010

using namespace std;

int a, b, n;
long long fact[LIMIT];
long long result = 0ll;

bool check(int x)
{
    while(x)
    {
        if(x % 10 != a && x % 10 != b) return 0;
        x /= 10;
    }
    return 1;
}

long long Power(long long a, int b)
{
    long long ans = 1;
    for(long long i = a; b; b >>= 1, i = i * i % EXTREMELY)
        if(b & 1) ans = ans * i % EXTREMELY;
    return ans;
}

long long C(int k)
{
    return fact[n] * Power(fact[k] * fact[n - k] % EXTREMELY, EXTREMELY - 2) % EXTREMELY;
}

int main()
{
   // filein, fileout;
    scanf("%d%d%d", &a, &b, &n);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % EXTREMELY;
    for(int i = 0; i <= n; i++)
    {
        int x = i * a + (n - i) * b;
        if(check(x))
            result = (result + C(i)) % EXTREMELY;
    }
    printf("%I64d", result);
    return 0;
}