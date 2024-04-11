#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int tab[n];
	    for(int i=0;i<n;i++) cin>>tab[i];
	    if(tab[0]<tab[n-1]) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
    }
    return 0;
}