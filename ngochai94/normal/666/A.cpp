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

int n,can[10004];
set<string> ans;
string s,cur;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s;
    n=s.size();
    can[n-1]=5;
    for(int r = n-3; r>=4; r--)
    {
        if(can[r+2])
        {
            if(can[r+2]!=2||s.substr(r+1,2)!=s.substr(r+3,2))
            {
                can[r]+=2;
                ans.insert(s.substr(r+1,2));
            }
        }
        if(can[r+3])
        {
            if(can[r+3]!=3||s.substr(r+1,3)!=s.substr(r+4,3))
            {
                can[r]+=3;
                ans.insert(s.substr(r+1,3));
            }
        }
    }
    cout<<ans.size()<<endl;
    for(string ss:ans) cout<<ss<<endl;
}