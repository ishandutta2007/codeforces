#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
 
const int N = 5000000;
int mark[N + 5];
vector<int> prime;
int factor[N + 4];
 
void seive(int n)
{
    int i, j, rt = sqrt(n*1.0);
    for (i = 4; i <= n; i += 2)
        mark[i] = 1;
    mark[0] = mark[1] = 1;
    prime.push_back(2);
    for (i = 3; i <= n; i += 2)
    {
        if (mark[i] == 0)
        {
            prime.push_back(i);
            if (i <= rt)
            {
                for (j = i * i; j <= n; j += 2 * i)
                    mark[j] = 1;
            }
        }
    }
}
 
int fact(int n)
{
    int i, j, rt = sqrt(n * 1.0);
    int tm = n, c = 0;
    for (i = 0; tm != 1 && i < prime.size( ) && prime[i] <= rt; i++)
    {
        if (tm % prime[i] == 0)
        {
            while (tm % prime[i] == 0)
            {
                c++;
                tm /= prime[i];
            }
            rt = sqrt(tm);
        }
    }
    if (tm != 1)
        c++;
    return c;
}
 
void pre( )
{
    int i, c;
    factor[1] = 0;
    for (i = 2; i <= N; i++)
    {
        c = fact(i);
        factor[i] = factor[i - 1] + c;
    }
}
 
int main( )
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    seive(N);
    pre( );
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << factor[a] - factor[b] << "\n";
    }
    return 0;
}