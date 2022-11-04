#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll fastPow(ll a,ll k,ll m)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%m;
        a=a*a%m;
        k>>=1;
    }
    return res;
}
ll convert(string s,ll m)
{
    ll res=0;
    for(int i=0;i<(int)s.size();i++)
        res=(res*10+s[i]-'0')%m;
    return res;
}
const ll Mod=1000000007;
struct info
{
    ll val,len;
    info(){}
    info(ll _val,ll _len):val(_val),len(_len){}
    info(const string &t)
    {
        for(int i=(val=0);i<(int)t.size();i++)
            val=(val*10+t[i]-'0')%Mod;
        len=(int)t.size();
    }
    info operator + (const info &rhs)const
    {
        return info((val*fastPow(10,rhs.len,Mod)+rhs.val)%Mod,(len+rhs.len)%(Mod-1));
    }
    info operator ^ (const string &t)const
    {
        ll p=0,tmp=0;
        for(int i=0;i<(int)t.size();i++)
            p=(p*10+t[i]-'0')%(Mod-1);
        if(len)tmp=(fastPow(10,p*len,Mod)-1)*fastPow(fastPow(10,len,Mod)-1,Mod-2,Mod)%Mod;
        else for(int i=0;i<(int)t.size();i++)
            tmp=(tmp*10+t[i]-'0')%Mod;
        return info((val*tmp%Mod+Mod)%Mod,p*len%(Mod-1));
    }
};
bool isDigit(char x)
{
    return (x>='0' && x<='9');
}
string number(string &str,int &i)
{
    string res;
    while(i<(int)str.size() && isDigit(str[i]))
        res.push_back(str[i++]);
    return res;
}
info rangeSameLength(string l,string r)
{
    ll tl=convert(l,Mod),tr=convert(r,Mod);
    ll pl=convert(l,Mod-1),pr=convert(r,Mod-1);
    ll pw=fastPow(10,l.size(),Mod);
    ll tmp=(tr+1)*(fastPow(pw,pr-pl+Mod,Mod)-1)%Mod*fastPow(pw-1,Mod-2,Mod)%Mod;
    ll now=(tr-tl+Mod+1)*fastPow(pw,pr-pl+Mod+1,Mod)%Mod;
    now=(now-(tr-tl+Mod+2)*fastPow(pw,pr-pl+Mod,Mod)%Mod+Mod+1)%Mod;
    tmp=(tmp-now*fastPow(fastPow(pw-1,2,Mod),Mod-2,Mod)%Mod+Mod)%Mod;
    return info(tmp,(pr-pl+Mod)*l.size()%(Mod-1));
}
info rangeLength(int t)
{
    ll tl=fastPow(10,t-1,Mod),tr=fastPow(10,t,Mod)-1;
    ll pl=fastPow(10,t-1,Mod-1),pr=(fastPow(10,t,Mod-1)+Mod-2)%(Mod-1);
    ll pw=fastPow(10,t,Mod);
    ll tmp=(tr+1)*(fastPow(pw,pr-pl+Mod,Mod)-1)%Mod*fastPow(pw-1,Mod-2,Mod)%Mod;
    ll now=(tr-tl+Mod+1)*fastPow(pw,pr-pl+Mod+1,Mod)%Mod;
    now=(now-(tr-tl+Mod+2)*fastPow(pw,pr-pl+Mod,Mod)%Mod+Mod+1)%Mod;
    tmp=(tmp-now*fastPow(fastPow(pw-1,2,Mod),Mod-2,Mod)%Mod+Mod)%Mod;
    return info(tmp,(pr-pl+Mod)*t%(Mod-1));
}
info range(string l,string r)
{
    if(l.size()==r.size())return rangeSameLength(l,r);
    info now=rangeSameLength(l,string(l.size(),'9'));
    for(int i=(int)l.size()+1;i<=(int)r.size()-1;i++)
        now=now+rangeLength(i);
    return now+rangeSameLength("1"+string((int)r.size()-1,'0'),r);
}
info expression(string &str,int &i)
{
    info now=info(0,0);
    string lhs="";
    while(i<(int)str.size())
    {
        if(isDigit(str[i]))
            lhs=number(str,i);
        if(i==(int)str.size())break;
        char ty=str[i++];
        if(ty==')')return now+info(lhs);
        if(ty=='(')
        {
            now=now+(expression(str,i)^lhs);
            lhs.clear();
        }
        if(ty=='+')now=now+info(lhs);
        if(ty=='-')
        {
            string rhs=number(str,i);
            now=now+range(lhs,rhs);
            lhs.clear();
        }
    }
    return now+info(lhs);
}
int main()
{
    string str;
    cin>>str;
    int ptr=0;
    cout<<expression(str,ptr).val<<endl;
    return 0;
}