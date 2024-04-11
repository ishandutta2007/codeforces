#include<bits/stdc++.h>

using namespace std;

long long n;
void solve()
{
    cin>>n;

    long long ima = 0;
    int par = 0;
    while(n)
    {
        long long take = 0;
        if (n&1) take = 1; else
            take = n/2;

        if (take>4)
        {
            if (take %2 == 0)
            {
                take = 1;
            }
        }

        n -=take;
        if (!par) ima+=take;
        par^=1;
    }

    cout<<ima<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
        solve();
}