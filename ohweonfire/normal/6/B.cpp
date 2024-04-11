#include <iostream>
#include <set>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main()
{
    int n,m;
    char room[105][105],p;
    cin>>n>>m>>p;
    rep(i,n) rep(j,m) cin>>room[i][j];
    set<char>s;
    s.insert(p);
    s.insert('.');
    rep(i,n) rep(j,m) if(room[i][j]==p)
    {
        if(i!=0)s.insert(room[i-1][j]);
        if(i!=n-1)s.insert(room[i+1][j]);
        if(j!=0)s.insert(room[i][j-1]);
        if(j!=m-1)s.insert(room[i][j+1]);
    }
    cout<<(int)s.size()-2;
    return 0;
}