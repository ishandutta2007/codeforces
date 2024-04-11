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

const bool multi=0;

int tab[100007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
		int n,ans=inf;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>tab[i];
		sort(tab+1,tab+n+1);
		if(n<3)
		{
			cout<<tab[1]-1<<endl;
			continue;
		}
		vector <int> vec;
		for(int i=1;i<=10000000;i++)
		{
			bool b=1;
			int act=1,res=0;
			for(int j=1;j<=n;j++)
			{
				if(act>1000000000000000)
				{
					b=0;
					break;
				}
				res+=abs(tab[j]-act);
				act*=i;
			}
			if(!b) break;
			else ans=min(ans,res);
		}
		cout<<ans<<endl;
    }

    return 0;
}