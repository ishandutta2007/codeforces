#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
const int MX = 1<<17;
const int MOD = 1000000007;
const LL mod2 = 1000000007 * 1LL * 1000000007;
typedef pair<int,int> pii;

#define pb push_back
#define f first
#define s second

string str;
int n;
int dpp[3][3][100001];

int alt(int idx,int t,int l)
{
    if(idx>=n)return 0;
    if(dpp[t][l][idx] == -1)
    {
        int ans=0;
        if(t!=2)
        {
            if(t==0)
            {
                ///cout<<"ajsbcj\n";
                int t1=0,t2=0,t3=0;
                ///flipping start...
                if(!l)t1=1+alt(idx+1,1,(str[idx]-'0'==1?2:1));
                else if(str[idx]-'0'==l)t1=1+alt(idx+1,1,(str[idx]-'0'==1?2:1));
                else t1=1+alt(idx+1,t,str[idx]-'0');
                ///not starting flipping...
                if(!l)t2=max(1+alt(idx+1,t,str[idx]-'0'),alt(idx+1,t,l));
                else if(str[idx]-'0'!=l)t2=max(1+alt(idx+1,t,str[idx]-'0'),alt(idx+1,t,l));
                ans=max(t1,max(t2,t3));
            }
            else
            {
                ///cout<<"opkdl\n";
                int t1=0,t2=0,t3=0;
                ///stop flipping
                t1=1+alt(idx+1,2,str[idx]-'0');
                ///continue flipping
                if(str[idx]-'0'==l)t2=1+alt(idx+1,t,(str[idx]-'0'==1?2:1));
                else t2=1+alt(idx+1,2,str[idx]-'0');
                ans=max(t1,max(t2,t3));
            }
        }
        else
        {
            ///cout<<"why\n";
            int t1=0,t2=0,t3=0;
            if(str[idx]-'0'!=l)t1=1+alt(idx+1,t,str[idx]-'0');
            else t1=alt(idx+1,t,l);
            ans=max(t1,t2);
        }
        dpp[t][l][idx]=ans;
    }
    return dpp[t][l][idx];
}

int main() {
    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='0')str[i]='1';
        else str[i]='2';
    }
    memset(dpp,-1,sizeof dpp);
    cout<<alt(0,0,0)<<'\n';
    return 0;
}