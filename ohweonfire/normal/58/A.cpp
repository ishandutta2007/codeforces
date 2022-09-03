#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    cin>>a;
    string b="hello";
    int j=0;
    for(int i=0;i<=a.size();i++)
    if(j<5&&a[i]==b[j])j++;
    if(j==5)cout<<"YES";else cout<<"NO";
    return 0;
}