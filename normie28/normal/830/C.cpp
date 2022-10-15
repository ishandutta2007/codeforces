#include <bits/stdc++.h>
using namespace std;
long long j,k,res=0;
int n,i,a[102];
vector<long long> ck,lis;
void ad (int x)
{
for (int i=1; i<=sqrt(x); i++) {ck.push_back(i); ck.push_back(ceil(float(x)/i));}
}
int ct(long long x)
{
long long res=0,tp=0;
for (int i=1;i<=n;i++) {tp=(long)a[i]%x; if (tp) res+=x-tp;}
return (res<=k); 
}
long long bs(long long l,long long r)
{
//if (l>=999999998)cout<<"bs("<<l<<','<<r<<") ";
if (l==r) if (ct(l)) return l; else return -1;
long long mid=(l+r)/2; mid++;
if (ct(mid)) return bs(mid,r); else return bs(l,mid-1); 
}
int main()
{
cin>>n>>k;
for (i=1;i<=n;i++) {cin>>a[i]; ad(a[i]);}
sort(ck.begin(),ck.end());
lis.push_back(ck[0]);
for (i=1;i<ck.size();i++) if (ck[i]-ck[i-1]) lis.push_back(ck[i]);
lis.push_back(1000000000000);
for (i=0;i<lis.size()-1;i++)
{
j=bs(lis[i],lis[i+1]-1);
if (j>res) res=j;
}
//cout<<lis[lis.size()-1]<<endl;
cout<<res;
}