#include<bits/stdc++.h>
using namespace std;
char t[4] = {'A', 'A', 'B', 'A'};
int b[4] = {1, 0, 1, 2};
int main()
{
    int x;cin>>x;
    x%=4;
    cout<<b[x]<<" "<<t[x]<<endl;
}