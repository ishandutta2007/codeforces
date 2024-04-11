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
        double n;
        double PI=3.141592653589793238;
        cin>>n;
        n*=2;
        printf("%.8f \n",(2/(2*tan(PI/n))));
    }
    return 0;
}