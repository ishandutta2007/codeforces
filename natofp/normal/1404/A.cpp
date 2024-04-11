#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define mp make_pair

using namespace std;


const int nax = 3e5 + 5;
int czy[nax][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        string s; cin>>s;
        bool ok = true;
        for(int i=0;i<k;i++)
        {
            czy[i][0] = czy[i][1] = false;
        }
        for(int i=0;i<n;i++)
        {
            int pos = i % k;
            if(s[i] != '?') czy[pos][s[i]-'0'] = true;
        }
        for(int i=0;i<k;i++)
        {
            if(czy[i][0] && czy[i][1])
            {
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(czy[i%k][0]) s[i] = '0';
            else if(czy[i%k][1]) s[i] = '1';
        }
        int zero = 0;
        int one = 0;
        int znaki = 0;
        for(int i=0;i<k;i++)
        {
            if(s[i] == '0') zero++;
            else if(s[i] == '1') one++;
            else znaki++;
        }
        if(min(zero,one) + znaki >= max(zero,one)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }

    return 0;
}