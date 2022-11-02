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

const bool multi=1;

int ile[107];

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
    	for(int i=0;i<=100;i++) ile[i]=0;
		int n,x;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			ile[x]++;
		}
		int a,b,it=0;
		while(ile[it]>=1) it++;
		a=it,it=0;
		while(ile[it]>=2) it++;
		b=it;
		cout<<a+b<<endl;
    }
    return 0;
}