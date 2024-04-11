#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    vector<vector<int>> pre_min(a),pre_max(a);
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
        {
            pre_max[i][j]=max(pre_max[i][j],pre_max[i][j-1]);
            pre_min[i][j]=min(pre_min[i][j],pre_min[i][j-1]);
        }
    vector<vector<int>> suf_min(a),suf_max(a);
    for(int i=0;i<n;i++)
        for(int j=m-2;j>=0;j--)
        {
            suf_max[i][j]=max(suf_max[i][j],suf_max[i][j+1]);
            suf_min[i][j]=min(suf_min[i][j],suf_min[i][j+1]);
        }
    vector<int> idx(n);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int x,int y){
        return a[x][0]>a[y][0];
    });
    for(int k=0;k+1<m;k++)
    {
        vector<int> lef_min(n),lef_max(n);
        for(int i=0;i<n;i++)
        {
            lef_min[i]=pre_min[i][k];
            lef_max[i]=pre_max[i][k];
        }
        vector<int> rig_min(n),rig_max(n);
        for(int i=0;i<n;i++)
        {
            rig_min[i]=suf_min[i][k+1];
            rig_max[i]=suf_max[i][k+1];
        }
        vector<int> lef_red(n),rig_red(n);
        for(int i=0;i<n;i++)
            lef_red[i]=lef_min[idx[i]],rig_red[i]=rig_max[idx[i]];
        for(int i=1;i<n;i++)
        {
            lef_red[i]=min(lef_red[i],lef_red[i-1]);
            rig_red[i]=max(rig_red[i],rig_red[i-1]);
        }
        vector<int> lef_blu(n),rig_blu(n);
        for(int i=0;i<n;i++)
            lef_blu[i]=lef_max[idx[i]],rig_blu[i]=rig_min[idx[i]];
        for(int i=n-2;i>=0;i--)
        {
            lef_blu[i]=max(lef_blu[i],lef_blu[i+1]);
            rig_blu[i]=min(rig_blu[i],rig_blu[i+1]);
        }
        for(int i=0;i+1<n;i++)
            if(lef_red[i]>lef_blu[i+1] && rig_red[i]<rig_blu[i+1])
            {
                string res(n,'B');
                for(int j=0;j<=i;j++)
                    res[idx[j]]='R';
                return 0*printf("YES\n%s %d\n",res.c_str(),k+1);
            }
    }
    return 0*printf("NO\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}