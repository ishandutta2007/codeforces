#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        long long x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<1+(x2-x1)*(y2-y1)<<endl;

    }
    return 0;
}