#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    while(k>0)
    {
        if(n%10==0)
        {
            n=n/10;
            k--;
        }
        else
        {
            if(k>n%10)
            {
                k -= n%10;
                n = n-n%10;
            }
            else
            {
                n = n-k;
                k=0;
            }
        }
    }
    cout<<n<<endl;
}