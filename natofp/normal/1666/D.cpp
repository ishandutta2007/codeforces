#include<bits/stdc++.h>
using namespace std;
bool odw[105];
void solve()
{
    for(int x=0;x<26;x++)
        odw[x] = false;
    string a,b;
    cin>>a>>b;
    while(!a.empty() && !b.empty())
    {
        if(a.back() == b.back())
        {
            //cout<<"XD "<<a.back()<<'\n';
            if(odw[b.back() - 'A'])
            {
                cout<<"NO\n";
                return;
            }
            a.pop_back();
            b.pop_back();
        }
        else
        {
            //cout<<"wtf "<<a.back()<<'\n';
            odw[a.back() - 'A'] = true;
            a.pop_back();
        }
    }
    if(b.empty())
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}