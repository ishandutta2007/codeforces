#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
string str;
int dp[10005][2];
vector<string>st;
int main()
{
    cin>>str;
    int n=(int)str.length();
    dp[n][0]=dp[n][1]=1;
    for(int i=n;i>=5;i--)
        for(int j=0;j<2;j++)
        {
            if(!dp[i][j])continue;
            if(j==0)
            {
                if(i-2>=5 && str.substr(i-2,2)!=str.substr(i,2))dp[i-2][0]=1;
                if(i-3>=5)dp[i-3][1]=1;
            }
            else
            {
                if(i-2>=5)dp[i-2][0]=1;
                if(i-3>=5 && str.substr(i-3,3)!=str.substr(i,3))dp[i-3][1]=1;
            }
        }
    for(int i=5;i<n-1;i++)
        if(dp[i+2][0] || dp[i+2][1])
            st.push_back(str.substr(i,2));
    for(int i=5;i<n-2;i++)
        if(dp[i+3][0] || dp[i+3][1])
            st.push_back(str.substr(i,3));
    sort(st.begin(),st.end());
    st.erase(unique(st.begin(),st.end()),st.end());
    cout<<(int)st.size()<<endl;
    for(int i=0;i<(int)st.size();i++)
        cout<<st[i]<<endl;
    return 0;
}