#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

long long n, lis[100005], pre[100005], ind;
set<pair<long long, int> > s;
multiset<long long> all;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    scanf("%lld", &n);
    For(i,1,1+n)
    {
        scanf("%lld", &lis[i]);
        pre[i]=pre[i-1]+lis[i];
    }
    all.insert(pre[n]);
    s.insert({1,0});
    s.insert({n,1});
    For(i,0,n)
    {
        cin>>ind;
        auto en=s.lower_bound({ind,1});
        auto st=en;
        st--;
        long long oldval = pre[en->first]-pre[st->first-1];
        all.erase(all.find(oldval));
        if(st->first!=ind)
        {
            s.insert({ind-1,1});
            all.insert(pre[ind-1]-pre[st->first-1]);
        }
        if(en->first!=ind)
        {
            s.insert({ind+1,0});
            all.insert(pre[en->first]-pre[ind]);
        }
        if(all.empty())
        {
            cout<<0<<endl;
            continue;
        }
        auto it=all.end();
        it--;
        cout<<*it<<endl;
    }
}