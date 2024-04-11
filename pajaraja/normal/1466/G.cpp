#include <bits/stdc++.h>
#define MAXN 100007
#define MOD 1000000007
using namespace std;
long long st[MAXN],cnt[30][MAXN];
int l,z;
string s,t,q,u;
long long calc(int d, int p)
{
    if(p+(1<<d)>=z) {long long res=cnt[q[p]-'a'][l]-(cnt[q[p]-'a'][d]*st[l-d])%MOD; if(res<0) res+=MOD; return res;}
    long long res=0;
    bool fas=false;
    for(int i=p;i<z;i+=(1<<(d+1))) if(q[i]!=t[d]) fas=true;
    if(!fas) {res=(res+calc(d+1,p+(1<<d))); if(res>MOD) res-=MOD;}
    fas=false;
    for(int i=p+(1<<d);i<z;i+=(1<<(d+1))) if(q[i]!=t[d]) fas=true;
    if(!fas) {res=(res+calc(d+1,p));  if(res>MOD) res-=MOD;}
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    st[0]=1; for(int i=1;i<MAXN;i++) st[i]=(st[i-1]*2LL)%MOD;
    int tl,queries; cin>>tl>>queries;
    cin>>s>>t;
    s+='*';
    int n=s.size();
    for(int i=0;i<tl;i++)
    {
        for(int j=0;j<26;j++) {cnt[j][i+1]=(2*cnt[j][i]); if(cnt[j][i+1]>MOD) cnt[j][i+1]-=MOD;}
        cnt[t[i]-'a'][i+1]++;
        if(cnt[t[i]-'a'][i+1]>MOD) cnt[t[i]-'a'][i+1]-=MOD;
    }
    while(queries--)
    {
        cin>>l>>u;
        int m=u.size();
        long long sol=0;
        for(int i=0;i<n;i++)
        {
            int t1=i;
            bool fas=false;
            q.clear();
            for(int j=0;j<m;j++)
            {
                if(t1+1==n) {q+=u[j]; t1=0; continue;}
                if(s[t1]!=u[j]) {fas=true; break;}
                t1++;
            }
            if(fas) continue;
            if(q.size()==0) {sol=sol+st[l]; if(sol>MOD) sol-=MOD;}
            else
            {
                if(l<20 && q.size()>=(1<<l)) continue;
                z=q.size();
                sol+=calc(0,0);
                if(sol>MOD) sol-=MOD;
            }
        }
        printf("%lld\n",sol);
    }
}