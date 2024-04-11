#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        int sum=0;
        int n; cin>>n;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x; sum+=x;
        }
        cout<<(sum+n-1)/n<<endl;
    }
    return 0;
}