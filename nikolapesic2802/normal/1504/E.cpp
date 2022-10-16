#include"bits/stdc++.h"
#define f first
#define s second
using namespace std;
main()
{
int n,a,c,i;
cin>>n;
long long d=0;
vector<pair<int,int>> s;
for(i=0;i<n;i++)cin>>a>>c,d+=c,s.push_back({a,c});
sort(s.begin(),s.end());
int m=s[0].f+s[0].s;
for(auto p:s){if(p.f>m)d+=p.f-m;m=max(m,p.f+p.s);}
printf("%lld\n",d);
}