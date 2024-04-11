#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        if(n==1) {cout<<-1<<"\n"; continue;}
        cout<<2;
        for(int i=1;i<n;i++) cout<<3;
        cout<<"\n";
    }
    return 0;
}