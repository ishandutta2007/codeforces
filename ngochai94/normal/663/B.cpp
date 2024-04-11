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

int t;
string s;
set<string> rep;

string tostr(long long x)
{
    string ret="";
    char c;
    while(x)
    {
        c='0'+x%10;
        x/=10;
        ret=c+ret;
    }
    return ret;
}

bool valid(string x)
{
    if(x.size()>4||x.size()==4&&(x[0]>'1'||x[0]=='1'&&x[1]=='9'&&(x[2]=='9'||x[2]=='8'&&x[3]=='9'))) return true;
    return false;
}

string f(string s)
{
    int cnt=-1;
    if(s[0]=='0') cnt=0;
    while(1)
    {
        cnt++;
        string tmp = tostr(cnt)+s;
        if(valid(tmp)&&!rep.count(tmp)) return tmp;
    }
}

string solve(string s)
{
    string tmp = "";
    for(int i = s.size()-1; i>=0; i--)
    {
        tmp = s[i]+tmp;
        string ss = f(tmp);
        //cout<<i<<' '<<ss<<endl;
        if(i==0) return ss;
        rep.insert(ss);
    }
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>s;
        s=s.substr(4,s.size()-4);
        rep.clear();
        cout<<solve(s)<<endl;
    }
}