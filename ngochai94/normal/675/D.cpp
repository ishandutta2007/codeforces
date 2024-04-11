#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

int n,val;
set<int> s,l,r;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>val;
    s.insert(val);
    For(i,1,n)
    {
        cin>>val;
        auto it = s.upper_bound(val);
        if(it==s.end())
        {
            it--;
            cout<<*it<<' ';
            r.insert(*it);
            s.insert(val);
            continue;
        }
        if(it==s.begin())
        {
            cout<<*it<<' ';
            l.insert(*it);
            s.insert(val);
            continue;
        }
        auto itt = s.upper_bound(val);
        itt--;
        if(l.count(*it))
        {
            r.insert(*itt);
            cout<<*itt<<' ';
        }
        else
        {
            l.insert(*it);
            cout<<*it<<' ';
        }
        s.insert(val);
    }
}