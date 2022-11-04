#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
using namespace std;
map<string,int>mp;
int get_id(const string &str)
{
    if(!mp[str])mp[str]=(int)mp.size();
    return mp[str];
}
const int MAXN=5005;
int l[MAXN],c[MAXN],r1[MAXN],r2[MAXN],ty[MAXN],val[MAXN];
string rn1[MAXN],rn2[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    string str;
    stringstream ss;
    getline(cin,str);
    for(int i=1;i<=n;i++)
    {
        getline(cin,str);
        ss.clear();
        ss.str(str);
        ss>>str;
        l[i]=get_id(str);
        ss>>str;//str==":="
        ss>>str;
        if(str[0]=='0' || str[0]=='1')rn1[i]=str;
        else r1[i]=(str=="?" ? -1 : get_id(str));
        if(ss>>str)
        {
            c[i]=2;
            if(str=="AND")ty[i]=0;
            if(str== "OR")ty[i]=1;
            if(str=="XOR")ty[i]=2;
            ss>>str;
            if(str[0]=='0' || str[0]=='1')rn2[i]=str;
            else r2[i]=(str=="?" ? -1 : get_id(str));
        }
        else c[i]=1;
    }
    string res[2];
    for(int j=0;j<2;j++)
        res[j].resize(m);
    for(int i=0;i<m;i++)
    {
        int cnt[2]={0,0};
        for(int j=0;j<2;j++)
            for(int k=1;k<=n;k++)
            {
                if(r1[k])val[k]=(r1[k]>0 ? val[r1[k]] : j);
                else val[k]=rn1[k][i]-'0';
                if(c[k]==2)
                {
                    int tmp=0;
                    if(r2[k])tmp=(r2[k]>0 ? val[r2[k]] : j);
                    else tmp=rn2[k][i]-'0';
                    if(ty[k]==0)val[k]&=tmp;
                    if(ty[k]==1)val[k]|=tmp;
                    if(ty[k]==2)val[k]^=tmp;
                }
                cnt[j]+=val[k];
            }
        for(int j=0;j<2;j++)
            res[j][i]='0'+(cnt[j]>cnt[j^1]);
    }
    for(int i=0;i<2;i++)
        cout<<res[i]<<endl;
    return 0;
}