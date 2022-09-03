#include <iostream>
#include <string>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
string name[55];
int wp[55],dg[55],sg[55];
bool cmp(int a,int b)
{
     if(wp[a]!=wp[b])return wp[a]>wp[b];
     else if(dg[a]!=dg[b])return dg[a]>dg[b];
     else return sg[a]>sg[b];
}
int main()
{
    int n;
    cin>>n;
    int n1=n*(n-1)/2,n2=n/2;
    rep(i,n)cin>>name[i],wp[i]=dg[i]=sg[i]=0;
    rep(i,n1)
    {
        string a,b,tmp;
        int ai,bi,p,q;
        char ch;
        cin>>tmp>>p>>ch>>q;
        a=tmp.substr(0,tmp.find("-"));
        b=tmp.substr(tmp.find("-")+1);
        ai=find(name,name+n,a)-name;
        bi=find(name,name+n,b)-name;
        if(p>q)wp[ai]+=3;
        else if(p<q)wp[bi]+=3;
        else wp[ai]++,wp[bi]++;
        dg[ai]+=p-q;sg[ai]+=p;
        dg[bi]+=q-p;sg[bi]+=q;
    }
    int a[55];
    rep(i,n)a[i]=i;
    sort(a,a+n,cmp);
    string s[28];
    rep(i,n2)s[i]=name[a[i]];
    sort(s,s+n2);
    rep(i,n2)cout<<s[i]<<endl;
    return 0;
}