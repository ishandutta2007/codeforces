#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    for (int i=n/2;i>0;i--){
        if (s.substr(0,i)==s.substr(i,i)){
            n-=i-1;
            break;
        }
    }
    cout<<n;
}