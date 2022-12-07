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

    string init[n];
    string fin[n];
    //vector<string> same;
    ll start,end;
    string ans="";
    string rep="";

    string ans_temp="";
    string rep_temp="";

    string pre="",post="",pre_temp,post_temp;

    ll flag = 0;
    ll len1,len2;
    ForA1(n)
    {
        cin>>init[i];
    }
    ll len=0;
    ForA1(n)
    {
        cin>>fin[i];
        len = fin[i].length();
        start=-1;
        for(ll j=0;j<len;j++)
        {
            if(fin[i][j] != init[i][j])
            {
                start = j;
                break;
            }
        }
        if(start==-1)
        {
            //same.push_back(fin[i]);
            continue;
        }
        for(ll j=len-1;j>=0;j--)
        {
            if(fin[i][j] != init[i][j])
            {
                end = j;
                break;
            }
        }

        
        len = end-start+1;
        ans_temp = init[i].substr(start,len);
        rep_temp = fin[i].substr(start,len);
        pre_temp = fin[i].substr(0,start);
        post_temp = fin[i].substr(end+1);
        reverse(pre_temp.begin(),pre_temp.end());
        if(ans!="")
        {
            if(ans!=ans_temp || rep!=rep_temp)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            len = min(pre.length(),pre_temp.length());
            flag = -1;
            for(ll j=0;j<len;j++)
            {
                if(pre_temp[j]!=pre[j])
                {
                    flag = j;
                    break;
                }
            }
            if(flag!=-1)
            {
                pre=pre.substr(0,flag);
            }
            else{
                if(pre.length() > pre_temp.length())
                    pre=pre_temp;
            }

            len = min(post.length(),post_temp.length());
            flag = -1;
            for(ll j=0;j<len;j++)
            {
                if(post_temp[j]!=post[j])
                {
                    flag = j;
                    break;
                }
            }
            if(flag!=-1)
            {
                post=post.substr(0,flag);
            }
            else{
                if(post.length() > post_temp.length())
                    post=post_temp;
            }
        }
        else
        {
            ans=ans_temp;
            rep=rep_temp;
            post=post_temp;
            pre=pre_temp;
        }
    }
    reverse(pre.begin(),pre.end());

    // cout<<pre<<endl;
    // cout<<ans<<endl;
    // cout<<post<<endl;
    // cout<<rep<<endl;
    if(ans=="")
    {
        cout<<"YES"<<endl;
        cout<<"a"<<endl;
        cout<<"a"<<endl;
        return 0;
    }
    string checker;
    ans=pre+ans+post;
    rep=pre+rep+post;
    len = rep.length();
    //len = same.size();
    size_t found;
    for(ll i=0;i<n;i++)
    {
        found = init[i].find(ans);
        if( found!=std::string::npos)
        {
            // cout<<i<<endl;
            // cout<<found<<endl;
            checker = fin[i].substr(found,len);
            // cout<<checker<<endl;
            if(checker != rep)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;
    cout<<ans<<endl;
    cout<<rep<<endl;
    return 0;
}