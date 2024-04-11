#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,y;cin>>x>>y;
    if (x==y) cout<<x<<"0 "<<y<<"1";
    else if (x+1==y) cout<<x<<"9 "<<y<<"0";
    else if (x==9 && y==1) cout<<"9 10";
    else cout<<-1;
    return 0;
}