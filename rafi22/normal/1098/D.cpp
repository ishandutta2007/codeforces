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

const bool multi=0;

int BIT[500007];
int que(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=BIT[x];
	return s;
}
void ins(int x,int s) {
	for (;x<=500000;x+=x&-x) BIT[x]+=s;
}
map<int,int>id;
multiset<int>S;

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
        int q;
        cin>>q;
        vector<pair<char,int>>Q(q);
        set<int>P;
        S.insert(inf);
        for(int i=0;i<q;i++)
        {
            cin>>Q[i].st>>Q[i].nd;
            P.insert(Q[i].nd);
        }
        int it=0;
        for(auto x:P) id[x]=++it;
        for(auto x:Q)
        {
            if(x.st=='+')
            {
                S.insert(x.nd);
                ins(id[x.nd],x.nd);
            }
            else
            {
                S.erase(S.find(x.nd));
                ins(id[x.nd],-x.nd);
            }
            if(sz(S)==1)
            {
                cout<<0<<endl;
                continue;
            }
            multiset<int>::iterator it;
            int n=sz(S)-1,k=0,sum=*S.begin();
            while(true)
            {
                it=S.upper_bound(2*sum);
                if(*it==inf) break;
                if(2*que(id[*it]-1)<*it) k++;
                sum=que(id[*it]);
            }
            cout<<max(0LL,n-k-1)<<endl;
        }
    }

    return 0;
}