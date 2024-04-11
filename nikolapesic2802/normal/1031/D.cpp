#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
void mini(int& a,int b)
{
    a=min(a,b);
}
void mini(char& a,char b)
{
    a=min(a,b);
}
void maxi(int& a,int b)
{
    a=max(a,b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    auto inside=[&](int row,int col){
        return 0 <= row && 0 <=col && row <n && col <n;
    };
    cin >> n >> k;
    vector<string> mat(n);
    for(int i=0;i<n;i++)
        cin >> mat[i];
    int dp[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=INT_MAX;
    dp[0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i!=0)
                mini(dp[i][j],dp[i-1][j]);
            if(j!=0)
                mini(dp[i][j],dp[i][j-1]);
            if(mat[i][j]!='a')
                dp[i][j]++;
        }
    int pref=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(dp[i][j]<=k)
                maxi(pref,i+j+1);
    vector<pair<int,int> > list;
    set<pair<char,pair<int,int> > > why;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(dp[i][j]<=k&&i+j+1==pref){
                if(inside(i+1,j))
                    why.insert({mat[i+1][j],{i+1,j}});
                if(inside(i,j+1))
                    why.insert({mat[i][j+1],{i,j+1}});
            }
                //list.pb({i,j});
    string s(pref,'a');
    if(why.empty()&&s.size()==0){
            int i=0,j=0;
       if(inside(i+1,j))
                    why.insert({mat[i+1][j],{i+1,j}});
                if(inside(i,j+1))
                    why.insert({mat[i][j+1],{i,j+1}});
        s+=mat[0][0];
    }
    while(!s.empty())
    {
        vector<pair<int,int> > mog;
        for(auto p:why)
        {
            if(p.first==(*why.begin()).first)
            {
                mog.pb(p.second);
            }
        }
        if(mog.empty())
            break;
        s+=(*why.begin()).first;
        why.clear();
        for(auto p:mog)
        {
            int i=p.first;
            int j=p.second;
            if(inside(i+1,j))
                why.insert({mat[i+1][j],{i+1,j}});
            if(inside(i,j+1))
                why.insert({mat[i][j+1],{i,j+1}});
        }
    }
    assert(s.size()==2*n-1);
    cout << s <<"\n";
    return 0;
}