#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    while(n>0)
    {
        string s;
        cin>>s;

        int lower = 0;
        int upper = 0;
        int digit = 0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]<='z'&&s[i]>='a')
                lower++;
            if(s[i]<='Z'&&s[i]>='A')
                upper++;
            if(s[i]<='9'&&s[i]>='0')
                digit++;
        }

        if(lower==0&&upper ==0)
        {
            cout<<"aA";
            for(int i=2;i<s.length();i++)
            {
                cout<<s[i];
            }
            cout<<endl;
            n--;
            continue;
        }

        if(digit==0&&upper ==0)
        {
            cout<<"0A";
            for(int i=2;i<s.length();i++)
            {
                cout<<s[i];
            }
            cout<<endl;
            n--;
            continue;
        }

        if(lower==0&&digit ==0)
        {
            cout<<"a0";
            for(int i=2;i<s.length();i++)
            {
                cout<<s[i];
            }
            cout<<endl;
            n--;
            continue;
        }

        if(lower==0)
        {
            if(upper>1)
            {
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]<='Z'&&s[i]>='A')
                    {
                        s[i]='a';
                        break;
                    }
                }
                cout<<s<<endl;
                n--;
                continue;
            }
            else
            {
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]<='9'&&s[i]>='0')
                    {
                        s[i]='a';
                        break;
                    }
                }
                cout<<s<<endl;
                n--;
                continue;
            }
        }

        if(upper==0)
        {
            if(lower>1)
            {
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]<='z'&&s[i]>='a')
                    {
                        s[i]='A';
                        break;
                    }
                }
                cout<<s<<endl;
                n--;
                continue;
            }
            else
            {
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]<='9'&&s[i]>='0')
                    {
                        s[i]='A';
                        break;
                    }
                }
                cout<<s<<endl;
                n--;
                continue;
            }
        }

        if(digit==0)
        {
            if(upper>1)
            {
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]<='Z'&&s[i]>='A')
                    {
                        s[i]='0';
                        break;
                    }
                }
                cout<<s<<endl;
                n--;
                continue;
            }
            else
            {
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]<='z'&&s[i]>='a')
                    {
                        s[i]='0';
                        break;
                    }
                }
                cout<<s<<endl;
                n--;
                continue;
            }
        }

        cout<<s<<endl;


        n--;
    }

    return 0;
}