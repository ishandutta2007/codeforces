#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define pob pop_back
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
    	string str,ans1="",ans2="";
    	bool b=0;
    	cin>>str;
    	for(int i=0;i<n;i++)
    	{
    		if(str[i]=='0')
    		{
    			ans1+='0';
    			ans2+='0';
    		}
    		else if(str[i]=='1'&&!b)
    		{
    			ans1+='1';
    			ans2+='0';
    			b=1;
    		}
    		else if(str[i]=='1'&&b)
    		{
    			ans1+='0';
    			ans2+='1';
    		}
    		else if(!b)
    		{
    			ans1+='1';
    			ans2+='1';
    		}
    		else
    		{
    			ans1+='0';
    			ans2+='2';
    		}
    	}
    	cout<<ans1<<endl<<ans2<<endl;
    }

    return 0;
}