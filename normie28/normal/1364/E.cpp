#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int p[(1<<11)+5];
int query(int i,int j)
{
    cout<<'?'<<' '<<i<<' '<<j<<endl;
    int ans;
    cin>>ans;
    assert(ans!=-1);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> qp;
    for (int i=1;i<=n;i++)
    qp.push_back(i);
    shuffle(qp.begin(),qp.end(),rng);
    int a=qp[0],b=qp[1],val=query(a,b);
    for (int i=2;i<n;i++)
    {
        int tmp=query(b,qp[i]);
        if (tmp<val)
        {
            a=qp[i];
            val=tmp;
        }
        else if (tmp==val)
        {
            b=qp[i];
            val=query(a,qp[i]);
        }
    }
    int idx;
    while (1)
    {
        int i=uniform_int_distribution<int>(1,n)(rng);
        if (i==a || i==b)
        continue;
        int t1=query(i,a),t2=query(i,b);
        if (t1!=t2)
        {
            idx=(t1<t2? a:b);
            break;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (i!=idx)
        p[i]=query(i,idx);
    }
    cout<<'!';
    for (int i=1;i<=n;i++)
    cout<<' '<<p[i];
    cout<<endl;
}