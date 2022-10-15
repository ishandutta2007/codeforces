#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
   while(s.length()>1)
{
    int a=0;
    for (auto g : s) a+=g-48;
    s=to_string(a);
}
cout<<s;
}