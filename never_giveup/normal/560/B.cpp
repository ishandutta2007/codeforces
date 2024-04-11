#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    ios::sync_with_stdio(false);
    int a1,a2,a3,b1,b2,b3;
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    if((a1>=a2+a3 && b1>=max(b2,b3)) || (a1>=a2+b3 && b1>=max(b2,a3)) || (a1>=b2+a3 && b1>=max(a2,b3)) || (a1>=b2+b3 && b1>=max(a2,a3))
       || (b1>=a2+a3 && a1>=max(b2,b3)) || (b1>=a2+b3 && a1>=max(b2,a3)) || (b1>=b2+a3 && a1>=max(a2,b3)) || (b1>=b2+b3 && a1>=max(a2,a3)))
        cout<<"YES";
    else
        cout<<"NO";
}