#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,m,tmp1,tmp2,tmp3,dp[10004];
map<long long,vector<string> > hash3;
set<int> hash1,hash2;
string cur,s;
char c;

bool match(string& s1,string& s2)
{
    int n=s2.size();
    if(s1.size()!=n) return false;
    For(i,0,n) if(s2[i]!=s1[n-1-i]&&s1[n-1-i]!=s2[i]+'a'-'A') return false;
    return true;
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>s>>m;
    while(m--)
    {
        cin>>cur;
        tmp1=tmp2=tmp3=0;
        for(int i=cur.size()-1;i>=0;i--)
        {
            c=cur[i];
            if(c>='A'&&c<='Z') c+='a'-'A';
            // tmp1*=967;
            // tmp1+=c;
            // tmp1%=1299827;
            // tmp2*=28351;
            // tmp2+=c;
            // tmp2%=mod;
            tmp3*=116101;
            tmp3+=c;
            tmp3%=200560490131ll;
            //if(cur=="losing") cout<<cur[i]<<endl;
        }
        //if(cur=="losing") cout<<tmp1<<' '<<tmp2<<' '<<tmp3<<endl;
        // hash1.insert(tmp1);
        // hash2.insert(tmp2);
        hash3[tmp3].pb(cur);
    }
    reset(dp,-1);
    dp[n]=n;
    for(int i=n-1;i>=0;i--)
    {
        tmp1=tmp2=tmp3=0;
        For(j,i,n)
        {
            // tmp1*=967;
            // tmp1+=s[j];
            // tmp1%=1299827;
            // tmp2*=28351;
            // tmp2+=s[j];
            // tmp2%=mod;
            tmp3*=116101;
            tmp3+=s[j];
            tmp3%=200560490131ll;
            //if(i==24&&j==29) cout<<tmp1<<' '<<tmp2<<' '<<tmp3<<endl;
            if(dp[j+1]!=-1&&hash3.count(tmp3))
            {
                dp[i]=j;
                break;
            }
        }
    }
    //For(i,0,n+1) cout<<dp[i]<<' ';
    tmp1=0;
    //cout<<match("arik","Kira");
    while(tmp1!=n)
    {
        cur=s.substr(tmp1,dp[tmp1]-tmp1+1);
        tmp3=0;
        For(i,tmp1,dp[tmp1]+1)
        {
            tmp3*=116101;
            tmp3+=s[i];
            tmp3%=200560490131ll;
        }
        //if(!tmp1) for(string ss:hash3[tmp3]])
        for(string ss:hash3[tmp3]) if(match(cur,ss))
        {
            cout<<ss<<' ';break;
        }
        tmp1=dp[tmp1]+1;
    }
}