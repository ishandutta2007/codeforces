#include <bits/stdc++.h>

using namespace std;
int n,m,t,q[500][500],p[500];
int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    ios::sync_with_stdio(false);
    cin>>n>>m>>t;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>q[i][j];
    for(int i=0;i<n;i++){
        int now=0;
        for(int j=0;j<m;j++)
            if(q[i][j]==0){
              p[i]=max(p[i],now);
              now=0;
            }
            else
            now++;
        p[i]=max(p[i],now);
    }
    for(int iter=0;iter<t;iter++){
        int i,j1;
        cin>>i>>j1;
        i--;
        j1--;
        q[i][j1]=(q[i][j1]+1)%2;
        int now=0;
        p[i]=0;
        for(int j=0;j<m;j++)
            if(q[i][j]==0){
              p[i]=max(p[i],now);
              now=0;
            }
            else
            now++;
        p[i]=max(p[i],now);
        int ans=0;
        for(int j=0;j<n;j++)
            ans=max(ans,p[j]);
        cout<<ans<<'\n';
    }
}