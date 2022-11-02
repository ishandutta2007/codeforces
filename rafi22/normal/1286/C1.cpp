#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

multiset<string>P;
int ile[107][26];

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
        int n;
        cin>>n;
        string s;
        cout<<"? "<<1<<" "<<n<<endl;
        for(int i=0; i<(n+1)*n/2; i++)
        {
            cin>>s;
            sort(all(s));
            P.insert(s);
        }
        if(n!=1)
        {
            cout<<"? "<<2<<" "<<n<<endl;
            for(int i=0; i<(n-1)*n/2; i++)
            {
                cin>>s;
                sort(all(s));
                P.erase(P.find(s));
            }
        }
        for(auto x:P)
        {
            for(auto y:x) ile[sz(x)][y-'a']++;
        }
        cout<<"! ";
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(ile[i][j]==ile[i-1][j]) continue;
                cout<<(char)(j+'a');
            }
        }
        cout<<endl;
    }

    return 0;
}