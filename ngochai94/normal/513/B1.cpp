#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define pb push_back
#define mod 1000000007

int n,m;

void solve(int up,int down,int mm)
{
    if(up==down) cout<<up<<' ';
    else
    {
        int k=up-down-1;
        if(mm<=(1<<k))
        {
            cout<<down<<' ';
            solve(up,down+1,mm);
        }
        else
        {
            solve(up,down+1,mm-(1<<k));
            cout<<down<<' ';
        }
    }
}

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n>>m;
    solve(n,1,m);
    return 0;
}