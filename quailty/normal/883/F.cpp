#include<bits/stdc++.h>
#define sc scanf
#define pr printf
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef double db;
typedef long long ll;

set<string> Set;

string ch(string s)
{
    string ans1="";
    for(auto &c:s)
    {
        if(c=='u') ans1+="oo";
        else ans1+=c;
    }
    string ans2="";
    for(int i=(int)ans1.size()-1;i>=0;i--)
    {
        ans2+=ans1[i];
        if(ans1[i]=='h')
        {
            while(i>0 && ans1[i-1]=='k') i--;
        }
    }
    return ans2;
}

int main()
{
    int n;
    sc("%d",&n);
    while(n--)
    {
        string s;
        cin>>s;
        Set.insert(ch(s));
    }
    pr("%d\n",Set.size());
    return 0;
}