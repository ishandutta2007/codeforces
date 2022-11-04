#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
char str[MAXN];
vector<int> normalize(const vector<ll> &a)
{
    vector<ll> x=a;
    sort(x.begin(),x.end());
    vector<int> res(a.size());
    for(size_t i=0;i<a.size();i++)
        res[i]=lower_bound(x.begin(),x.end(),a[i])-x.begin()+1;
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d%s",&n,str+1);
        vector<ll> val_mi,val_mx;
        ll v=0;
        val_mi.push_back(v);
        for(int i=1;i<n;i++)
        {
            if(str[i]=='<')v++;
            else v-=MAXN;
            val_mi.push_back(v);
        }
        ll l=0,r=0;
        val_mx.push_back(l);
        for(int i=1;i<n;i++)
        {
            if(str[i]=='<')val_mx.push_back(++l);
            else val_mx.push_back(--r);
        }
        vector<int> res=normalize(val_mi);
        for(int i=0;i<n;i++)
            printf("%d%c",res[i]," \n"[i==n-1]);
        res=normalize(val_mx);
        for(int i=0;i<n;i++)
            printf("%d%c",res[i]," \n"[i==n-1]);

    }
    return 0;
}