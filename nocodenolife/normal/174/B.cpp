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

#define modder 998244353
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
    
    string s;
    cin>>s;
    vector<int> answers;
    
    ll counter = 0;
    ll flag=0;
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]=='.')
        {
            if(flag==0)
            {
                if( counter>8 || counter==0)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                answers.push_back(counter);
            }
            else
            {
                if(counter<2 || counter>11)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                if(counter<8)
                {
                    answers.push_back(1);
                    answers.push_back(counter-1);
                }
                else
                {
                    answers.push_back(3);
                    answers.push_back(counter-3);
                }
            }
            counter=0;
            flag=1;
        }
        else
        {
            counter++;
        }
    }
    if(flag==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(counter>3 || counter<=0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        answers.push_back(counter);
    }
    cout<<"YES"<<endl;
    counter=0;
    for(ll i=0;i<answers.size();i++)
    {
        for(ll j=0;j<answers[i];j++)
        {
            cout<<s[counter];
            counter++;
        }
        counter++;
        cout<<".";
        i++;
        for(ll j=0;j<answers[i];j++)
        {
            cout<<s[counter];
            counter++;
        }
        cout<<endl;
    }
    
    
    return 0;
}