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

int ile[30];

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
		int n;
		cin>>n;
		string str;
		for(int i=0;i<26;i++) ile[i]=0;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			for(int j=0;j<str.size();j++) ile[str[j]-97]++;
		}
		bool ok=1;
		for(int i=0;i<26;i++) if(ile[i]%n!=0) ok=0;
		if(!ok) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
    }

    return 0;
}