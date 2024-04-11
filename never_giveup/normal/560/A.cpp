#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    ios::sync_with_stdio(false);
    bool f = 0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1)
            f=1;
    }
    if(f)
        cout<<-1;
    else
        cout<<1;
}