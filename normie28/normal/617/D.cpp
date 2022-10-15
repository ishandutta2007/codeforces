
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

typedef  long long int            ll;
typedef  pair<int,int> 	          ii;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector<char>	          vc;
#define sf                    scanf
#define pf                    printf
 
#define sf1(a)                scanf("%d", &a)
 
#define sf1ll(a)              scanf("%I64d", &a)

 
void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
 
const int res = 1e5 + 50;
const ll mod = 1e9 + 7;
 
int n, sum, total, ans, dp[res];
ii a[res];
 void ot(int x)
 {
 	cout<<x+1;
 	exit(0);
 }
int main()
{
	long long x[3],y[3],match[3],z[3];
	cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
	if ((x[0]==x[1])and(x[1]==x[2])) ot(0);
	if ((y[0]==y[1])and(y[1]==y[2])) ot(0);
	if ((x[0]==x[1])and((y[0]-y[2])*(y[1]-y[2])>=0)) ot(1);
	if ((x[1]==x[2])and((y[0]-y[1])*(y[0]-y[2])>=0)) ot(1);
	if ((x[0]==x[2])and((y[0]-y[1])*(y[2]-y[1])>=0)) ot(1);
	if ((y[0]==y[1])and((x[0]-x[2])*(x[1]-x[2])>=0)) ot(1);
	if ((y[1]==y[2])and((x[0]-x[1])*(x[0]-x[2])>=0)) ot(1);
	if ((y[0]==y[2])and((x[0]-x[1])*(x[2]-x[1])>=0)) ot(1);
	ot(2);
}