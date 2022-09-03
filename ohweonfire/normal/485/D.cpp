#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<deque>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<string>
#include<set>
#include<stack>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
const ll INF=1<<30;
const ll LINF=1ll<<61;
const double eps=1e-7;
set<int>s;
vector<int>v;
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        s.insert(-x);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++)v.PB(-(*it));
    s.clear();
    int ans=0;s.insert(v[0]);
    for(int i=1;i<v.size();i++)
    {
        for(int j=v[i];j<=1000000;)
        {
            j+=v[i];
            int k=*(--s.lower_bound(j));
            if(k<v[i])continue;
            ans=max(ans,k%v[i]);
        }
        s.insert(v[i]);
    }
    printf("%d\n",ans);
    return 0;
}