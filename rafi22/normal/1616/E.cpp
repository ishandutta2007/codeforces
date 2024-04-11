#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int BIT[100007];
vector<int>l[26];
int n;
int que(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=BIT[x];
	return s;
}
void ins(int x,int s) {
	for (;x<=n;x+=x&-x) BIT[x]+=s;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) BIT[i]=0;
        for(int i=0;i<26;i++) l[i].clear();
        string s,t;
        cin>>s>>t;
        s='#'+s;
        for(int i=n;i>0;i--) l[s[i]-'a'].pb(i);
        t='#'+t;
        int ans=inf,cnt=0;
        for(int i=1;i<=n;i++)
        {
           // cout<<cnt<<endl;
            for(int j=0;j<t[i]-'a';j++)
            {
                if(sz(l[j])==0) continue;
                ans=min(ans,cnt+l[j].back()+que(n)-que(l[j].back())-i);
            }
            int j=t[i]-'a';
            if(sz(l[j])==0) break;
            cnt+=l[j].back()+que(n)-que(l[j].back())-i;
            ins(l[j].back(),1);
            l[j].pop_back();
        }
        if(ans==inf) cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}