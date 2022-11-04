#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=1000005;
vector<pair<string,int> >v;
vector<string>res[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin>>str;
    for(int i=0;i<(int)str.size();i++)
        if(str[i]==',')str[i]=' ';
    stringstream ss;
    ss.str(str);
    while(ss>>str)
    {
        int tmp;
        ss>>tmp;
        v.push_back(make_pair(str,tmp));
    }
    stack<int>st;
    st.push(-1);
    for(int i=0,j=1;i<(int)v.size();i++)
    {
        while(st.top()==0)j--,st.pop();
        res[j].push_back(v[i].first);
        st.top()--;
        st.push(v[i].second),j++;
    }
    int mx=0;
    for(int i=1;i<MAXN && !res[i].empty();i++)
        mx=i;
    cout<<mx<<endl;
    for(int i=1;i<=mx;i++)
    {
        for(int j=0;j<(int)res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}