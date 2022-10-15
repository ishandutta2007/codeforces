#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define F first
#define S second
#define pi acos(-1)
#define EPS 1e-9
#define MOD 998244353
void IOS(){ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);}
int dx[9]= {1,-1,0,0,1,-1,1,-1,0};
int dy[9]= {0,0,1,-1,1,-1,-1,1,0};
const int N=200005;
#define pr pair<int,int>
priority_queue<pr> pq;
int n,m,i,j,res,add;
string a,b;

 long long bow (long long a, long long x)
 {
 	if (!x) return 1;
	long long res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return (res)%MOD;
 }
 
int main()
{
    IOS();
    cin>>n>>m;
    cin>>a>>b;
    for (i=0;i<m;i++)
    {
    if (n-1-i>=0) if (a[n-1-i]=='1') {add+=bow(2,i);add%=MOD;}
    if (b[m-1-i]=='1') res+=add;
    res%=MOD;
    }
    cout<<res;
}
/*Formal balloting is required for elections to a principal organ of the UN such as the Council, even if candidates have been endorsed by their regional group and are running on a clean slate. If no candidate garners the requisite number of votes in the first round, the voting is restricted to the top vote getters (the number of countries included on the restricted ballot is limited to twice the number of vacant seats: two candidates for a single unfilled seat or four candidates for two unfilled seats). This restricted voting continues for up to three additional rounds of voting. If a candidate still fails to obtain the minimum number of votes, unrestricted voting is reopened for any candidates for up to three rounds. This pattern of restricted and unrestricted voting continues until a candidate is successful in securing a seat. (Extended multiple rounds of voting have occurred in the past, most recently in 2006, when Guatemala and Venezuela went through 47 rounds of voting before both withdrew and Panama was elected in the 48th round. The 1979 election established an all-time high for Security Council elections with 154 rounds of voting between Colombia and Cuba before Mexico was elected in the 155th round as a compromise candidate.)*/