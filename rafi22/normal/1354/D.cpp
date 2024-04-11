#include <bits/stdc++.h>

using namespace std;

int tree[4000007];
int res,n,q,a, pot=1;

void Tquerry(int v,int k)
{
    if(v>=pot)
    {
        res=v-pot+1;
        return;
    }
    if(tree[2*v]>=k) Tquerry(2*v,k);
    else Tquerry(2*v+1,k-tree[2*v]);
}


int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    cin>>n>>q;
    while (pot<n)
    {
        pot*=2;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int y=pot+a-1;
        tree[y]++;
        while(y>1)
        {
            y/=2;
            tree[y]++;
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>a;
        if(a>0)
        {
            int y=pot+a-1;
            tree[y]++;
            while(y>1)
            {
                y/=2;
                tree[y]++;
            }
        }
        else
        {
            Tquerry(1,abs(a));
            int y=pot+res-1;
            tree[y]--;
            while(y>1)
            {
                y/=2;
                tree[y]--;
            }
        }
    }
    for(int i=pot;i<=2*pot;i++)
    {
        if(tree[i]>0)
        {
            cout<<i-pot+1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;


    return 0;
}